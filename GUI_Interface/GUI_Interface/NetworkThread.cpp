// NetworkThread.cpp
#define _WINSOCK_DEPRECATED_NO_WARNINGS //inet_ntoa | maybe i'll handle this in future

#include "NetworkThread.h"

#define Criptare "FileSharing52643AmicuLL" //Ce criptare xDD Ca trimite fiecare aplicatie cheia de "criptare" :)))

NetworkThread::NetworkThread() {
    setPort(12345);
    setBroadcastAddress("192.168.1.255"); //this is the default broadcast IP ADDR
    setBroadcastInterval(200); //5 times in a sec //200ms
    setBroadcastCheckInterval(800); //once 800ms
    setBroadcastCheckIterations(3); //3 times| will check for 800ms*3 = 2400ms = 2.4s
    srand(time(0)); int randVal = rand();
    sockaddr_in ownAddr;
    ownAddr.sin_addr.s_addr = inet_addr("4.0.4.0"); //404 not found ? :D
}

NetworkThread::~NetworkThread() { // ce as putea sa rup aici? Debug time pe memory use :D A nice memeory time session

}
void NetworkThread::SignalingMeAvailable(bool param) { //boolean parameter for signaling my presence until i establish a connection with a server/client? may i implement multi-user manipulation? The speed will half also...?
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

    sockaddr_in broadcastAddress; //some broadcasting parameters initialization
    broadcastAddress.sin_family = AF_INET; //IPv4
    broadcastAddress.sin_port = htons(getPort()); //the port will be initialized from config file
    broadcastAddress.sin_addr.s_addr = inet_addr(getBroadcastAddress()); //as this also

    BOOL reuseAddr = TRUE; //for testing? debug
    if (setsockopt(broadcastSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuseAddr, sizeof(reuseAddr)) == SOCKET_ERROR) {
        std::cerr << "Error SO_REUSEADDR for broadcast socket. Error code: " << WSAGetLastError() << std::endl;
        closesocket(broadcastSocket);
        WSACleanup();
        return;
    }
    while (param) { //here is the param that makes the broadcast signal unkillable XD Undead? until rip is true xD
        char* bcastMessage = nullptr;
        const char* broadcastMessage = Criptare; //my encryption key lmao
        if (ownAddr.sin_addr.s_addr == inet_addr("4.0.4.0")) { //for ignoring myself and putting a special key that will identify me
            char* bcastMessage = new char[std::to_string(randVal).length() + 1];
            strcpy_s(bcastMessage, std::to_string(randVal).length() + 1, std::to_string(randVal).c_str()); //sending the unique random key generatod as identificator
            sendto(broadcastSocket, bcastMessage, strlen(bcastMessage), 0, (struct sockaddr*)&broadcastAddress, sizeof(broadcastAddress)); //sending the key broadcasted
        }
        else {
            if (bcastMessage != nullptr) delete[] bcastMessage; //memory free
            sendto(broadcastSocket, broadcastMessage, strlen(broadcastMessage), 0, (struct sockaddr*)&broadcastAddress, sizeof(broadcastAddress)); //normal message... ENCRYPTED XD
        }
        Sleep(NetworkThread::getBroadcastInterval()); //sayin' hello to other, so they can see me :D
    }
    closesocket(broadcastSocket);//if param = false, otherwise it will continue forever
    WSACleanup();
    return;
}
void NetworkThread::StartBroadcast() { //this should start the broadcast and here i should control it... as i detach the thread, i can let the OS control it, but i dont' wanna to signal me as available if i'm connected?
    bool rip = false; //rip false indeed because rip true would be strange for making it grow... or rip true for the LAN? :P
    std::thread broadcastingThread([this, rip]() {
        SignalingMeAvailable(!rip);
        });
    //std::thread broadcastingThread(&NetworkThread::SignalingMeAvailable, !rip);
    broadcastingThread.detach(); //detached bcs i don't wanna get "blocked"
    if (!rip) rip = !rip;
}

bool NetworkThread::IsServerAvailable() { //also checking my signal also + saving my ip
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error initializing Winsock." << std::endl;
        return false;
    }

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0); //UDP
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Error socket creation." << std::endl;
        WSACleanup();
        return false;
    }

    BOOL broadcastEnable = TRUE; //for debug
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char*)&broadcastEnable, sizeof(broadcastEnable)) == SOCKET_ERROR) {
        std::cerr << "Error setting BROADCAST option on broadcast socket listener. " << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    sockaddr_in broadcastAddr; //broadcast receiving socket (it "listen" to every ip address)
    memset(&broadcastAddr, 0, sizeof(broadcastAddr)); //initializing the all struct params with 0 
    broadcastAddr.sin_family = AF_INET; //still IPv4, but we are localhost anyway :D
    broadcastAddr.sin_port = htons(PORT); //port will be given from getter
    broadcastAddr.sin_addr.s_addr = INADDR_ANY; //Listen to any ip (0.0.0.0), but it will be the broadcast

    BOOL reuseAddr = TRUE; //for debug (idk if i'll remove this)
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&reuseAddr, sizeof(reuseAddr)) == SOCKET_ERROR) {
        std::cerr << "Error setting SO_REUSEADDR option for 'client' socket. Error code: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    if (bind(sockfd, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr)) == SOCKET_ERROR) { //binding the socket to the ip, ofc
        std::cerr << "Error linking socket to 'broadcasted' IP. Error code: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    char buffer[1024]; //the buffer is kinda small? Or is it to big for sending some shitty messages?
    sockaddr_in clientAddr; //here i'll save my ip if i'll catch the key. Also, i can catch other ip addresses here  if so
    int clientAddrLen = sizeof(clientAddr);

    for (int i = 0; i < getBroadcastCheckIterations(); i++) { //if server is not found, i'll be the server
        std::cout << "Iteration [" << i + 1 << "]\r";
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(sockfd, &readSet);

        struct timeval timeout;
        timeout.tv_sec = 0; //0 seconds, ofc
        timeout.tv_usec = getBroadcastCheckInterval() * 100;  // 250 ms

        int ready = select(sockfd + 1, &readSet, nullptr, nullptr, &timeout); //handeling multiple connections
        if (ready > 0) {
            SSIZE_T bytesRead = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen); //incoming data (Also from me)
            if (bytesRead == SOCKET_ERROR) {
                std::cerr << "Error receiving data." << std::endl;
                closesocket(sockfd);
                WSACleanup();
                return false;
            }

            buffer[bytesRead] = '\0';
            if (bytesRead != 0) {
                if (strcmp(buffer, std::to_string(randVal).c_str()) == 0) { //comparing if the value catched is my "private" key, if so, i'll save my ip for future problems
                    ownAddr.sin_addr.s_addr = clientAddr.sin_addr.s_addr; //shall i make it with setter? Is local host anyway
                } //how i'm gonna save the others ip? If i'll be the server? I'll send their ipaddres. And if they know it, is hearth warming? Indeed it is bcs they'll listen to their broadcast and they can catch it itself
                if (ownAddr.sin_addr.s_addr != clientAddr.sin_addr.s_addr) { //if no me
                    if (strcmp(buffer, Criptare) == 0) { //checking the Encrypted key (xDDDD) in case other device broadcasts also and it will make false triggers
                        char clientIP[INET_ADDRSTRLEN]; //signaling my presence ... deprecated.... you mother
                        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, sizeof(clientIP));
                        std::cout << "Signal arrived from '" << clientIP/*inet_ntoa(clientAddr.sin_addr)*/ << "' with the correct encryption key: " << buffer << std::endl;
                        return true;
                    }
                }
            }
        }
        Sleep(getBroadcastCheckInterval()); //not broadcasting always, ofc... i'm not a monster... just 1000 per second
    }
    closesocket(sockfd);
    WSACleanup();
    return false;
}

void NetworkThread::StartClient() {
    // Implementare client
    // Realizare conexiune cu un server
}

void NetworkThread::StartServer() {
    // Implementare server
    // Acceptare o conexiune cu un client
}

void NetworkThread::BroadcastServerInfo() {
    // Implementare broadcast? Nu cred ca mai e nevoie, am gandit-o gresit initial. we'll see
}

bool NetworkThread::ReceiveBroadcast() {
    // nu e necesar also? ...
    return false;
}
/////ramane de vazut cand revin la aplicatie de o sa mai stiu ce sa fac xDD