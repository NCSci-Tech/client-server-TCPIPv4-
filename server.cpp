#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    // Create TCP socket
    int servSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (servSocket == -1) {
        cerr << "Failed to create socket!" << endl;
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(servSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Bind failed!" << endl;
        close(servSocket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(servSocket, 5) == -1) {
        cerr << "Listen failed!" << endl;
        close(servSocket);
        return -1;
    }
    cout << "Server is listening on port 8080..." << endl;

    // Accept a connection from a client
    int clientSocket = accept(servSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        cerr << "Failed to accept connection!" << endl;
        close(servSocket);
        return -1;
    }
    cout << "Connection established with client." << endl;

    // Receive message from client
    char buffer[1024] = { 0 };
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        cout << "Message from client: " << buffer << endl;

        // Prompt server operator for response
        string response;
        cout << "Enter response to client: ";
        getline(cin, response);

        // Send typed response to client
        send(clientSocket, response.c_str(), response.size(), 0);
        cout << "Response sent to client." << endl;
    } else {
        cerr << "Failed to receive message!" << endl;
    }

    // Close sockets
    close(clientSocket);
    close(servSocket);

    return 0;
}
