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

int main(int argc, char* argv[]) {
    int sockfd, len, ret;
    char buf[MAX_LINE];

    sockfd = tcp_open_client(argv[1], argv[2]);
    if (sockfd < 0) {
        perror("Connection failed");
        exit(1);
    }

    snprintf(buf, sizeof(buf),
             "GET / HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             argv[1]);

    send(sockfd, buf, strlen(buf), 0);

    while (1) {
        if ((ret = readready(sockfd)) < 0)
            break;
        if (ret > 0) {
            if (readline(sockfd, buf, MAX_LINE) <= 0)
                break;
            fputs(buf, stdout);
        }
    }

    close(sockfd);
    return 0;
}