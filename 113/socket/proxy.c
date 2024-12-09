#include "arpa/inet.h"
#include "errno.h"
#include "netdb.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "unistd.h"

#define MAX_LINE 4096

// Utility function to resolve a hostname to an IP address
in_addr_t my_inet_addr(char* host) {
    in_addr_t inaddr;
    struct hostent* hp;
    inaddr = inet_addr(host);
    if (inaddr == INADDR_NONE && (hp = gethostbyname(host)) != NULL) {
        bcopy(hp->h_addr, (char*)&inaddr, hp->h_length);
    }
    return inaddr;
}

// Open a TCP connection to the server
int tcp_open_client(char* host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = my_inet_addr(host);
    serv_addr.sin_port = htons(port);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Initialize a TCP server socket
int tcp_open_server(char* port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(port));

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        return -1;
    }

    return sockfd;
}

// Forward data between two sockets
void forward_data(int from_sock, int to_sock) {
    char buf[MAX_LINE];
    ssize_t len;

    while ((len = recv(from_sock, buf, sizeof(buf), 0)) > 0) {
        send(to_sock, buf, len, 0);
    }
}

void handle_client(int client_sock) {
    char request[MAX_LINE], host[MAX_LINE], path[MAX_LINE];
    int server_sock, port = 80;
    char *host_start, *path_start;
    ssize_t len;

    len = recv(client_sock, request, sizeof(request) - 1, 0);
    if (len <= 0) {
        close(client_sock);
        return;
    }
    request[len] = '\0';

    if (parse_url(request, host, path) < 0) {
        close(client_sock);
        return;
    }

    host_start = host;
    path_start = strchr(host, '/');
    if (path_start) {
        *path_start = '\0';
        path_start++;
    } else {
        path_start = "";
    }

    server_sock = tcp_open_client(host, port);
    if (server_sock < 0) {
        fprintf(stderr, "Failed to connect to %s\n", host);
        close(client_sock);
        return;
    }

    snprintf(request, sizeof(request),
             "GET /%s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path_start, host);
    send(server_sock, request, strlen(request), 0);

    forward_data(server_sock, client_sock);

    close(server_sock);
    close(client_sock);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd, client_sock;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    sockfd = tcp_open_server(argv[1]);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to open proxy server on port %s\n", argv[1]);
        exit(1);
    }

    printf("Proxy server running on port %s...\n", argv[1]);

    for (;;) {
        clilen = sizeof(cli_addr);
        client_sock = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        if (fork() == 0) {
            close(sockfd);
            handle_client(client_sock);
            exit(0);
        }

        close(client_sock);
    }

    close(sockfd);
    return 0;
}
