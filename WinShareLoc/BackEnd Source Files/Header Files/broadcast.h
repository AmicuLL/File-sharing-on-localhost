#ifndef BROADCAST_H
#define BROADCAST_H

#include "utils.h"
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

const int INET_ADDRSTRLEN = 16; //max len for IPv4

void sendBroadcast(const sockaddr_in& broadcastAddr, const BroadcastData& data, bool& broadcasting);
void receiveBroadcast(SOCKET sock, bool& recvBroadcast);

void updateBroadcast(bool& broadcasting, bool& recvBroadcast, bool& createdBroad, bool& createdRecvBroad, bool& stop, int* portPtr, BroadcastData data, SOCKET recvSock);


sockaddr_in setUpSendingBroadcastAddress(int PORT);
sockaddr_in setUpReceivingBroadcastAddres(int PORT);

#endif // BROADCAST_H
