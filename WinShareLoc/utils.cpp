#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <winsock2.h>
#include <winbase.h>
#include <Lmcons.h>

const char* getLoggedUser() { //Get windows user name
    wchar_t username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (GetUserNameW(username, &username_len)) {
        char* convertedUsername = new char[username_len + 1];
        wcstombs(convertedUsername, username, username_len + 1);
        return convertedUsername;
    } else {
        return "Failed to get username";
    }
}

const char* getDesktopName() { //Get computer name assigned in windows
    char* desktopName = new char[128];
    gethostname(desktopName, 128);
    return desktopName;
}

const char* getOS() { //cross platform? Reimplementing this in another way
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&info))) { 
        std::string osString = std::to_string(info.dwMajorVersion) + " | " + std::to_string(info.dwMinorVersion); //for now, only win ver
        char* osCString = new char[osString.length() + 1];
        strcpy(osCString, osString.c_str());
        return osCString;
    } else {
        return "OS undefined"; //if runned on linux||macOS ... also, network functions are cross platform? SHOULD TRY wxWidgets FUNCTIONS.
    }
}

BroadcastData setInfo(Status status, const char* type) {
    BroadcastData data;
    const char* username = getLoggedUser();
    const char* desktopName = getDesktopName();
    const char* os = getOS();

    data.type = type;
    data.desktopName = desktopName;
    data.desktopUser = username;
    data.transferPort = 1234;
    data.status = status;
    data.os = os;

    //delete[] username;
    //delete[] desktopName;
    //delete[] os;

    return data;
}

std::string statusToString(Status status) {
    switch (status) {
        case AVAILABLE: return "AVAILABLE";
        case CONNECTED: return "CONNECTED";
        case SHARING: return "SHARING";
        default: return "UNKNOWN";
    }
}