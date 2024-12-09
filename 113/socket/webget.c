#include "arpa/inet.h"
#include "errno.h"
#include "netdb.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "unistd.h"

#define MAX_LINE 1024

in_addr_t my_inet_addr(char* host) {
    in_addr_t inaddr;
    struct hostent* hp;
    inaddr = inet_addr(host);
    if (inaddr == INADDR_NONE && (hp = gethostbyname(host)) != NULL)
        bcopy(hp->h_addr, (char*)&inaddr, hp->h_length);
    return inaddr;
}

int tcp_open_client(char* host, char* port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = my_inet_addr(host);
    serv_addr.sin_port = htons(atoi(port));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 || connect(sockfd, (struct sockaddr*)&serv_addr,
                                                                  sizeof(serv_addr)) < 0) {
        return -1;
    }

    return sockfd;
}

int readready(int fd) {
    fd_set fds;
    int ret;
    struct timeval zerotimeval = {0, 0};

    do {
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        ret = select(fd + 1, &fds, NULL, NULL, &zerotimeval);
        if (ret >= 0)
            return ret;
    } while (errno == EINTR);

    return ret;
}

int readline(int fd, char* ptr, int maxlen) {
    int n, rc;
    char c;

    for (n = 1; n < maxlen; n++) {
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n')
                break;
        } else if (rc == 0) {
            if (n == 1)
                return 0;
            else
                break;
        } else {
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

int parse_url(const char* url, char* host, char* path) {
    char* url_copy = strdup(url);

    if (strncmp(url_copy, "http://", 7) == 0) {
        url_copy += 7;
    }

    char* slash = strchr(url_copy, '/');
    if (slash) {
        strcpy(path, slash);
        *slash = '\0';
    } else {
        strcpy(path, "/");
    }

    strcpy(host, url_copy);
    free(url_copy - 7);

    return 0;
}

int main(int argc, char* argv[]) {
    int sockfd, len, ret;
    char buf[MAX_LINE], request[MAX_LINE], host[MAX_LINE], path[MAX_LINE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    if (parse_url(argv[1], host, path) < 0)
        exit(1);

    sockfd = tcp_open_client(host, "80");
    if (sockfd < 0) {
        perror("Connection failed");
        exit(1);
    }

    snprintf(request, sizeof(request),
             "GET %s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    send(sockfd, request, strlen(request), 0);

    FILE* output = fopen("output.html", "w");

    while (1) {
        if ((ret = readready(sockfd)) < 0)
            break;
        if (ret > 0) {
            if (readline(sockfd, buf, MAX_LINE) <= 0)
                break;
            fputs(buf, stdout);
            fputs(buf, output);
        }
    }

    fclose(output);
    close(sockfd);
    return 0;
}
