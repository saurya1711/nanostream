
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from Client";
    char buffer[1024] = {0};

    // 1. Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // 2. Convert IPv4 address from text to binary
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Connect to server
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 4. Send and Receive
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent to server" << std::endl;
    read(sock, buffer, 1024);
    std::cout << "Server replied: " << buffer << std::endl;

    close(sock);
    return 0;
}


