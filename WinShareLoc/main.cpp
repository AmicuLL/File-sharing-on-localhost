#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <winsock2.h>
#include <string>
#include <winbase.h>
#include <Lmcons.h>
#include <stdio.h>
#include <atomic>

#include <conio.h> // _getch()

#include "broadcast.h"
#include "utils.h"

#define INFO_BUFFER_SIZE 32767

#pragma comment(lib, "ws2_32.lib")

static int PORT = 12345; // Portul pe care se trimite broadcast-ul

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("Failed to initialize Winsock");
        return 1;
    }
    
    SOCKET sendSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sendSock == INVALID_SOCKET) {
        perror("Error creating sending socket");
        WSACleanup();
        return 1;
    }

    SOCKET recvSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (recvSock == INVALID_SOCKET) {
        perror("Error creating receiving socket");
        closesocket(sendSock);
        WSACleanup();
        return 1;
    }

    int broadcastEnable = 1;
    if (setsockopt(recvSock, SOL_SOCKET, SO_BROADCAST, (const char*)&broadcastEnable, sizeof(broadcastEnable)) == SOCKET_ERROR) {
        perror("Error setting receiving socket option");
        closesocket(sendSock);
        closesocket(recvSock);
        WSACleanup();
        return 1;
    }

    sockaddr_in recvAddr = setUpReceivingBroadcastAddres(PORT);

    if (bind(recvSock, (struct sockaddr*)&recvAddr, sizeof(recvAddr)) == SOCKET_ERROR) {
        perror("Error binding receiving socket");
        closesocket(sendSock);
        closesocket(recvSock);
        WSACleanup();
        return 1;
    }
    BroadcastData data = setInfo();
    bool broadcasting = false, recvBroadcast = false, createdBroad = false, createdRecvBroad = false, stop = true;
    std::thread updateBroad;
    int* portPtr = &PORT;
    
    while(true){ //this is made just for testing | Maybe to complex
        system("cls");
        std::cout<<"[Broadcast messages can be found in Broadcasts.txt]\n";
        if(broadcasting) std::cout<<"\t[B] Disable broadcasting\n"; else std::cout<<"\t[B] Enable broadcasting\n";
        if(recvBroadcast)std::cout<<"\t[R] Disable receiving broadcasts\n"; else std::cout<<"\t[R] Enable receiving broadcasts\n";
        std::cout<<"\t[I] Broadcast info type   ["<< data.type <<"]\n";
        std::cout<<"\t[S] Broadcast status type   ["<< statusToString(data.status) << "]\n";
        //std::cout<<"\t[P] Broadcast transfer port\n";

        if(stop) std::cout<<"\t[O] Start\n\n"; else std::cout<<"\t[O] Stop\n\n";
        std::cout<<"\tAnswer:";
        char c = _getch();
        if(c == 'B' || c =='b'){
            if(broadcasting == false) std::cout<<"\tEnabled broadcasting";
            else std::cout<<"\tDisabled broadcasting";
            broadcasting = !broadcasting;
        }
        if(c == 'R' || c =='r'){
            if(recvBroadcast == false) std::cout<<"\tEnabled receiving broadcasts";
            else std::cout<<"\tDisabled receiving broadcasts";
            recvBroadcast = !recvBroadcast;
        }
        if(c == 'I' || c == 'i') {
            system("cls");
            std::cout<<"[Broadcast messages can be found in Broadcasts.txt]\n";
            std::cout<<"\tBroadcast actual info type:[" << data.type << "]\n";
            std::cout<<"\tEnter a broadcast info type:\t";
            char ch[512];
            std::cin>>ch;
            const char* tip = ch;
            data.type = tip;
        }
        if(c == 'S' || c == 's') {
            system("cls");
            std::cout<<"[Broadcast messages can be found in Broadcasts.txt]\n";
            std::cout<<"\tBroadcast actual status type:[" << statusToString(data.status) << "]\n";
            std::cout<<"\tSelect a broadcast status:\n\t";
            std::cout<<"\t[A] AVAILABLE\n\t\t[C] CONNECTED\n\t\t[S] SHARING";
            char ch = _getch();
            //c = _getch();
            if(ch == 'A' || ch == 'a') {
                data.status = AVAILABLE; 
                std::cout<<"\n\t\tSelected AVAILABLE!";}
            if(ch == 'C' || ch == 'c') {
                data.status = CONNECTED;
                 std::cout<<"\n\t\tSelected CONNECTED!";}
            if(ch == 'S' || ch == 's') {
                data.status = SHARING; 
                std::cout<<"\n\t\tSelected SHARING!";
            }
        }
        if(c == 'O' || c =='o'){
            if(stop == false) {
                std::cout<<"\tStopped!";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                delete[] data.desktopName;
                delete[] data.desktopUser;
                delete[] data.os;
                std::exit(0);
                //stop = true;
            }
            else {
                std::cout<<"\tStarted!";
                stop = false;
                updateBroad = std::thread ([&broadcasting, &recvBroadcast,  &createdBroad, &createdRecvBroad, &stop, portPtr, &data, recvSock](){
                    updateBroadcast(broadcasting, recvBroadcast, createdBroad, createdRecvBroad, stop, portPtr, data, recvSock);
                });
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //std::this_thread::sleep_for(std::chrono::seconds(500));
    delete[] data.desktopName;
    delete[] data.desktopUser;
    delete[] data.os;
    
    closesocket(sendSock);
    closesocket(recvSock);
    WSACleanup();

    return 0;
}

