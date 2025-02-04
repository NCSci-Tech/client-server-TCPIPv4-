TCP Server-Client Communication

Overview

This project consists of a simple TCP server and client written in C++. The server listens for incoming client connections, receives a message, and responds with a user-inputted response. The client connects to the server, sends a message, and displays the response received.

Features

Server:

Listens for incoming connections on port 8080.

Accepts a client connection.

Receives a message from the client.

Prompts the server operator for a response.

Sends the response back to the client.

Client:

Connects to the server on port 8080.

Takes user input and sends it to the server.

Receives and displays the server's response.

Prerequisites

A Linux-based system (or WSL on Windows) with a C++ compiler (e.g., g++).

Basic knowledge of TCP/IP socket programming.

Compilation

Compile both the server and client using g++:

# Compile the server
g++ -o server server.cpp

# Compile the client
g++ -o client client.cpp

Usage

Start the Server

Run the server first to start listening for connections:

./server

It will wait for an incoming client connection.

Start the Client

In a separate terminal, run the client:

./client

Enter a message when prompted and press Enter.

Example Interaction

Client:

Connected to the server.
Enter message: Hello, Server!
Message sent to server: Hello, Server!
Response from server: Hi, Client!

Server:

Server is listening on port 8080...
Connection established with client.
Message from client: Hello, Server!
Enter response to client: Hi, Client!
Response sent to client.

Error Handling

If the server fails to bind, ensure port 8080 is free.

If the client fails to connect, ensure the server is running.

Author

NCSci-Tech
