// NetworkThread.h
#pragma once

#include <winsock2.h>
#include <iostream>
#include <WS2tcpip.h>
#include <thread>
#include <stdlib.h>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")

class NetworkThread { //nothing special here, just implementation of the methods
public:
    NetworkThread();
    ~NetworkThread(); //gc :D 

    void SignalingMeAvailable(bool);
    void StartBroadcast();
    bool IsServerAvailable();
    void Start();
    void StartClient();
    void StartServer();

    void setPort(int PORT) {
        this->PORT = PORT;
    }
    void setBroadcastAddress(const char* BROADCAST_ADDRESS) {
        if (BROADCAST_ADDRESS != nullptr) {
            this->BROADCAST_ADDRESS = BROADCAST_ADDRESS;
        }
        else {
            this->BROADCAST_ADDRESS = "255.255.255.255";
        }
    }
    void setBroadcastInterval(int BROADCAST_INTERVAL) {
        this->BROADCAST_INTERVAL = BROADCAST_INTERVAL;
    }
    void setBroadcastCheckInterval(int BROADCAST_CHECK_INTERVAL) {
        this->BROADCAST_CHECK_INTERVAL = BROADCAST_CHECK_INTERVAL;
    }
    void setBroadcastCheckIterations(int BROADCAST_CHECK_ITERATIONS) {
        this->BROADCAST_CHECK_ITERATIONS = BROADCAST_CHECK_ITERATIONS;
    }
    int getPort() {
        return this->PORT;
    }
    const char* getBroadcastAddress() {
        return this->BROADCAST_ADDRESS;
    }
    int getBroadcastInterval() {
        return this->BROADCAST_INTERVAL;
    }
    int getBroadcastCheckInterval() {
        return this->BROADCAST_CHECK_INTERVAL;
    }
    int getBroadcastCheckIterations() {
        return this->BROADCAST_CHECK_ITERATIONS;
    }



private:
    int PORT;
    const char* BROADCAST_ADDRESS; //why private? IDK
    int BROADCAST_INTERVAL;
    int BROADCAST_CHECK_INTERVAL;
    int BROADCAST_CHECK_ITERATIONS;
    int randVal;
    sockaddr_in ownAddr; //this pc own ip address

    void BroadcastServerInfo();
    bool ReceiveBroadcast();
};
