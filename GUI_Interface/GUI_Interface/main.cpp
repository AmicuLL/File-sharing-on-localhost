#include <winsock2.h>
#include <iostream>
#include <cstring>
#include <WS2tcpip.h>
#include <thread>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

#define Criptare "FileSharing52643AmicuLL"

const int PORT = 12345;
const char BROADCAST_ADDRESS[] = "192.168.1.255";
const int BROADCAST_INTERVAL = 200;  //10 times in a sec //100ms
const int BROADCAST_CHECK_INTERVAL = 800;
const int BROADCAST_CHECK_ITERATIONS = 3; //will check for 400ms*3 = 1200ms
int randVal = 0; 
sockaddr_in ownAddr;

void broadcastServerInfo(bool param) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Eroare la initializarea Winsock." << std::endl;
        return;
    }

    SOCKET broadcastSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (broadcastSocket == INVALID_SOCKET) {
        std::cerr << "Eroare la crearea socket-ului de broadcast: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in broadcastAddress;
    broadcastAddress.sin_family = AF_INET;
    broadcastAddress.sin_port = htons(PORT);
    broadcastAddress.sin_addr.s_addr = inet_addr(BROADCAST_ADDRESS);
    
    BOOL reuseAddr = TRUE;
    if (setsockopt(broadcastSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuseAddr, sizeof(reuseAddr)) == SOCKET_ERROR) {
        std::cerr << "Eroare la setarea optiunii SO_REUSEADDR pentru primul socket. Cod de eroare: " << WSAGetLastError() << std::endl;
        closesocket(broadcastSocket);
        WSACleanup();
        return;
    }
    while (param) {
        char* bcastMessage = nullptr;
        const char* broadcastMessage = Criptare;
        if(ownAddr.sin_addr.s_addr == inet_addr("4.0.4.0")) {
            char* bcastMessage = new char[std::to_string(randVal).length() + 1];
            strcpy(bcastMessage, std::to_string(randVal).c_str());
            sendto(broadcastSocket, bcastMessage, strlen(bcastMessage), 0, (struct sockaddr*)&broadcastAddress, sizeof(broadcastAddress));        
        } else {
            if (bcastMessage != nullptr) delete[] bcastMessage;
            sendto(broadcastSocket, broadcastMessage, strlen(broadcastMessage), 0, (struct sockaddr*)&broadcastAddress, sizeof(broadcastAddress));
        }
        Sleep(BROADCAST_INTERVAL);
    }
    closesocket(broadcastSocket);
    WSACleanup();
}
//bool isClientsAvailable() { //asta trebuie implementat!
bool isServerAvailable() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Eroare la initializarea Winsock." << std::endl;
        return false;
    }
    
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Eroare la crearea socket-ului." << std::endl;
        WSACleanup();
        return false;
    }

    BOOL broadcastEnable = TRUE;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char*)&broadcastEnable, sizeof(broadcastEnable)) == SOCKET_ERROR) {
        std::cerr << "Eroare la setarea optiunii de broadcast. " << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(PORT);
    broadcastAddr.sin_addr.s_addr = INADDR_ANY;
    
    BOOL reuseAddr = TRUE;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&reuseAddr, sizeof(reuseAddr)) == SOCKET_ERROR) {
        std::cerr << "Eroare la setarea optiunii SO_REUSEADDR pentru primul socket. Cod de eroare: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    if (bind(sockfd, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr)) == SOCKET_ERROR) {
        std::cerr << "Eroare la legarea socket-ului de adresa de broadcast. Cod de eroare: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    char buffer[1024];
    sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    for(int i = 0; i<BROADCAST_CHECK_ITERATIONS; i++) {
        std::cout<<"Incercarea [" << i + 1 << "]\r";
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(sockfd, &readSet);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = BROADCAST_CHECK_INTERVAL * 100;  // 250 ms
        
        int ready = select(sockfd + 1, &readSet, nullptr, nullptr, &timeout);
        if (ready > 0) {
            ssize_t bytesRead = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
            if (bytesRead == SOCKET_ERROR) {
                std::cerr << "\nEroare la primirea datelor." << std::endl;
                closesocket(sockfd);
                WSACleanup();
                return false;
            }

            buffer[bytesRead] = '\0';
            if(bytesRead != 0) {
                if(strcmp(buffer,std::to_string(randVal).c_str())==0) {
                    ownAddr.sin_addr.s_addr = clientAddr.sin_addr.s_addr;
                    //return false; //are relevanta?
                } 
                if(ownAddr.sin_addr.s_addr != clientAddr.sin_addr.s_addr){
                    std::cout << "\nMesaj primit de la " << inet_ntoa(clientAddr.sin_addr) << ": " << buffer << std::endl;
                    if(strcmp(buffer, Criptare)!=0){
                        return false; //aici sigur nu are relevanta. Sau? A gasit server disp, initiem conectarea la el?
                    }
                    return true;
                }
            }
        }
        Sleep(BROADCAST_CHECK_INTERVAL);
    }
    closesocket(sockfd);
    WSACleanup();
    return false;
}

void startClient() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Eroare la initializarea Winsock." << std::endl;
        return;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Eroare la crearea socket-ului: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = inet_addr("192.168.1.255");  // Adresa IP a serverului

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Eroare la conectarea la server: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return;
    }

    // Aici tratez conexiunea Server -> Client

    closesocket(clientSocket);
    WSACleanup();
}

void startServer() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Eroare la initializarea Winsock." << std::endl;
        return;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Eroare la crearea socket-ului: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Eroare la legarea la port: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        std::cerr << "Eroare la ascultarea pentru conexiuni: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    std::cout << "Serverul asteapta conexiuni..." << std::endl;

    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Eroare la acceptarea conexiunii de la client: " << WSAGetLastError() << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return;
        }

        sockaddr_in clientAddress;
        int clientAddrLen = sizeof(clientAddress);
        if (getpeername(clientSocket, (struct sockaddr*)&clientAddress, &clientAddrLen) == 0) {
            char clientIP[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &clientAddress.sin_addr, clientIP, sizeof(clientIP));
            std::cout << "Conexiune de la client cu adresa IP: " << clientIP << std::endl;
        }

        // Tratez comunicarea cu clientul aici dupa ce implementez tot

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
}

int main() {
    srand(time(0)); randVal = rand(); ownAddr.sin_addr.s_addr = inet_addr("4.0.4.0");
    std::cout << "Detecteaza server disponibil..." << std::endl;
    std::thread BROADCASTING(broadcastServerInfo, true);
    Sleep(BROADCAST_CHECK_INTERVAL * BROADCAST_CHECK_ITERATIONS);
    if (isServerAvailable()) {
        startClient();
    } else {
        startServer();
    }
    
    return 0;
}

