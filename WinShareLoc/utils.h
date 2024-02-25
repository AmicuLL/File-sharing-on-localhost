#ifndef UTILS_H
#define UTILS_H

#include <string>

enum Status {
    AVAILABLE,
    CONNECTED,
    SHARING
};

struct BroadcastData {
    const char* type;
    const char* desktopName;
    const char* desktopUser;
    int transferPort;
    const char* os;
    Status status;
};

const char* getLoggedUser();
const char* getDesktopName();
const char* getOS();
BroadcastData setInfo(Status status = AVAILABLE, const char* type = "Info");

std::string statusToString(Status status);

#endif // UTILS_H
