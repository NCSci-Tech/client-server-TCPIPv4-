#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

int main()
{
    // Create a socket
    int cliSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (cliSocket == -1) {
        std::cerr << "Failed to create socket!" << std::endl;
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Request connection to the server
    if (connect(cliSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Connection failed!" << std::endl;
        close(cliSocket);
        return -1;
    }

    std::cout << "Connected to the server." << std::endl;

    // Input message to send
    std::string message;
    std::cout << "Enter message: ";
    std::getline(std::cin, message);

    // Send the message to the server
    if (send(cliSocket, message.c_str(), message.size(), 0) == -1) {
        std::cerr << "Failed to send message!" << std::endl;
    } else {
        std::cout << "Message sent to server: " << message << std::endl;
    }

    // Receive response from the server
    char buffer[1024] = { 0 };
    int bytesReceived = recv(cliSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        std::cout << "Response from server: " << buffer << std::endl;
    } else {
        std::cerr << "Failed to receive response from server!" << std::endl;
    }

    // Close the socket
    close(cliSocket);

    return 0;
}
