// let's see what I come up with here

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 500

int main (int argc, char *argv[]) {
    printf("It's running so far");

    char buf[BUF_SIZE];
    struct addrinfo hints;
    struct addrinfo *result, *rp;


    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = 0;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;


    int s = getaddrinfo("aaronspage.com\0", NULL, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }
    for(rp = result; rp != NULL; rp = rp->ai_next) {
        printf("result:\n  family: %d\n  socktype: %d\n  protocol: %d\n", rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        printf("  canonname: %s\n", rp->ai_canonname);
        printf("  sockaddr:\n");
        printf("    family: %d\n    data: %s\n", rp->ai_addr->sa_family, rp->ai_addr->sa_data);
    }

    exit(0);
    
    

}
