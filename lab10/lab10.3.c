// server3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server started\n");

    client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    printf("Client connected\n");

    read(client_fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    char *reply = "Hello, client!";
    send(client_fd, reply, strlen(reply), 0);

    close(client_fd);
    close(server_fd);
    return 0;
}
