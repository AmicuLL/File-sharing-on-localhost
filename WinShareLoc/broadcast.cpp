#include "broadcast.h"
#include <iostream>
#include <thread>
#include <chrono>

#include <fstream> //for test now

void sendBroadcast(const sockaddr_in& broadcastAddr, const BroadcastData& data, bool& broadcasting) {
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
        perror("Error socket creation!");
        return;
    }

    int broadcastEnable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<char*>(&broadcastEnable), sizeof(int)) == SOCKET_ERROR) {
        perror("Error setting socket option!");
        closesocket(sock);
        return;
    }

    char buffer[512];
    /*sprintf(buffer,
            "{\nType: %s\nDesktop name: %s\nDesktop user: %s\nTransfer Port: %d\nOS: %s\nStatus: %s\n}",
            &data.type, &data.desktopName, &data.desktopUser, &data.transferPort,
            &data.os, (data.status == AVAILABLE) ? "AVAILABLE" : ((data.status == CONNECTED) ? "CONNECTED" : "SHARING"));*/

    while(broadcasting) {
        sprintf(buffer,
            "{\nType: %s\nDesktop name: %s\nDesktop user: %s\nTransfer Port: %d\nOS: %s\nStatus: %s\n}",
            data.type, data.desktopName, data.desktopUser, data.transferPort,
            data.os, (data.status == AVAILABLE) ? "AVAILABLE" : ((data.status == CONNECTED) ? "CONNECTED" : "SHARING"));

        if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr)) == SOCKET_ERROR) {
            perror("Error sending broadcast");
        }
        std::this_thread::sleep_for(std::chrono::seconds((data.status == AVAILABLE) ? 2 : 5));
    }

    closesocket(sock);
}

void receiveBroadcast(SOCKET sock, bool& recvBroadcast) { //send a mem ref param for a buffer that would read the memory in another function
    sockaddr_in senderAddr;
    int senderAddrLen = sizeof(senderAddr);
    char buffer[512]; //will be a mem ref (return the buffer isn't possible in this case) ?
    int bytesRead;
    timeval timeout = { 0, 1000 };
    
    while (recvBroadcast) {
        memset(buffer, 0, sizeof(buffer));
        fd_set rs;
        FD_ZERO(&rs);
        FD_SET(sock, &rs);
        if (FD_ISSET(sock, &rs))
        {
            bytesRead = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&senderAddr, &senderAddrLen);
        }
        
        if (bytesRead == SOCKET_ERROR) {
            std::cout<<WSAGetLastError();
            perror("Error receiving broadcast message.\n");
            continue;
        }
        

        char ipStr[INET_ADDRSTRLEN];
        strncpy(ipStr, inet_ntoa(senderAddr.sin_addr), INET_ADDRSTRLEN);
        //std::cout << "Received broadcast from: [" << ipStr << "]:" << std::endl << buffer << std::endl; //for testing
        
        

        std::ofstream outputFile("Broadcasts.txt",std::ios::app);
        if (!outputFile.is_open()) {
            std::cerr << "Error creating/oppening Broadcasts.txt file" << std::endl;
            return;
        }
        outputFile << "\t\tReceived broadcast from: [" << ipStr << "]:" << std::endl << buffer << std::endl << "\n\n\n"; //writing the broadcast for debug (when i can't use my another pc for listening)
    }
}
//i don't mind if i get help implementing this thing... For now it works like this: A base thread for 2 threads corresponding to broadcasts and receving them.
void updateBroadcast(bool& broadcasting, bool& recvBroadcast, bool& createdBroad, bool& createdRecvBroad, bool& stop, int* portPtr, BroadcastData data, SOCKET recvSock){
    std::thread sendBroad, recvBroad;
    while(true) {
        if(!createdBroad){
            sendBroad = std::thread([portPtr, &data, &broadcasting]() {
                sendBroadcast(setUpSendingBroadcastAddress(*portPtr), data, broadcasting);
            });
            createdBroad = true;
        }
        if(!createdRecvBroad) {
            recvBroad = std::thread([recvSock, &recvBroadcast]() {
                receiveBroadcast(recvSock, recvBroadcast);
            });
            createdRecvBroad = true;
        }
        if(!broadcasting) {
            sendBroad.join();
            createdBroad = false;
        }
        if(!recvBroadcast) {
            recvBroad.join(); //for testing. at least for now?
            createdRecvBroad = false;
        }
        if(stop) {
            recvBroadcast = false;
            recvBroad.join();
            
            broadcasting = false;
            sendBroad.join();

            createdBroad = false;
            createdRecvBroad = false;
            //stop = false;
            //return;
        }
    }
}

sockaddr_in setUpSendingBroadcastAddress(int PORT) { //creating and returning the address for sending broadcast message
    sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcastAddr.sin_port = htons(PORT);
    return broadcastAddr;
}
sockaddr_in setUpReceivingBroadcastAddres(int PORT){ //creating and returning the address for receiving broadcast message
    sockaddr_in recvAddr;
    memset(&recvAddr, 0, sizeof(recvAddr));
    recvAddr.sin_family = AF_INET;
    recvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    recvAddr.sin_port = htons(PORT);
    return recvAddr;
}