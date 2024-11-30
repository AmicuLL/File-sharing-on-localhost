#include "Header Files/utils.h"

#include <stdexcept>
#include <winsock2.h>
#include <winbase.h>
#include <Lmcons.h>
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <string>

/*
JSONHandler jsonHandler("exemplu.json");

std::map<std::string, std::string> data = jsonHandler.readJSON();
for (const auto& pair : data) {
    std::cout << "\t " << pair.first << " \t:\t" << pair.second << "\n";
}

std::map<std::string, std::string> newData = {{{"Text1", "Valoare1"}, {"Text2", "Valoare2"}, {"Number1", "1234"}}};
//jsonHandler.writeJSON(newData);

std::string value = jsonHandler.findValue("MAAAAAAAAAAA-TA!");
if (!value.empty()) {
    std::cout << "Valoarea pentru cheia \"MAAAAAAAAAAA-TA!\" este " << value << "\n";
} else {
    std::cout << "Cheia \"Text1\" nu a fost gasita.\n";
}
*/


std::string selectedLanguage = "C:\\ProgramData\\WinShareLoc\\languages\\en_EN.json"; //default
JSONHandler translationHandler(selectedLanguage);
void setLanguage(const std::string& language) {
    language == "ro_RO" ? selectedLanguage = "C:\\ProgramData\\WinShareLoc\\languages\\ro_RO.json" : selectedLanguage = "C:\\ProgramData\\WinShareLoc\\languages\\en_EN.json";
    translationHandler = JSONHandler(selectedLanguage);
}

std::string getTranslatedData(const std::string& key) {
    std::string data = translationHandler.findValue(key);
    size_t pos = 0;
    while ((pos = data.find("\\n", pos)) != std::string::npos) {
        data.replace(pos, 2, "\n");
        pos += 1;
    }
    pos = 0;
    while ((pos = data.find("\\t", pos)) != std::string::npos) {
        data.replace(pos, 2, "\t");
        pos += 1;
    }
    return data;
}


JSONHandler::JSONHandler(const std::string& filename) : filename(filename) {
    this->data = readJSON();
}

std::map<std::string, std::variant<std::string, int>> JSONHandler::readJSON() {
    std::ifstream file(filename);
    std::map<std::string, std::variant<std::string, int>> data;

    if (!file.is_open()) {
        std::cerr << "Cannot open JSON file\n";
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t separatorPos = line.find(':'); //separate read line from label and values
        if (separatorPos != std::string::npos) { //If there exist a separation symbol typical for JSON ":", getting values and formatting them from line and making 2 substrings
            std::string key = line.substr(0, separatorPos); //first half label
            std::string value = line.substr(separatorPos, line.size()-1); //second half value
            
            size_t start_pos = key.find_first_of('"');
            size_t end_pos;
            if (start_pos != std::string::npos) {
                end_pos = key.find_first_of('"', start_pos + 1);
                if (end_pos != std::string::npos) {
                    key = key.substr(start_pos + 1, end_pos - start_pos - 1);
                }
            }
            
            start_pos = value.find_first_of('"');
            if(start_pos == std::string::npos) {
                start_pos= value.find_first_not_of(" :\t")-1;
            }
            if (start_pos != std::string::npos) {
                end_pos = value.find_last_of('"');
                if(end_pos == std::string::npos) {
                    end_pos = value.find_last_not_of(",\t ") + 1;
                }

                if (end_pos != std::string::npos) {
                    value = value.substr(start_pos + 1, end_pos - start_pos - 1);
                    int intValue;
                    try {
                        intValue = std::stoi(value);
                        data[key] = intValue;
                    }
                    catch (const std::invalid_argument&) {
                        data[key] = value;
                    }
                }
            }
            data[key] = value;
        }
    }
    return data;
}

void JSONHandler::writeJSON(const std::map<std::string, std::variant<std::string, int>>& data, const std::string& filename) {
    std::ofstream file(filename.empty() ? this->filename : filename);
    //std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    file << "{\n";
    for (auto it = data.begin(); it != data.end(); ++it) {
        file << "\t\"" << it->first << "\": ";
        if (std::holds_alternative<int>(it->second))
            file << std::get<int>(it->second);
        else
            file << "\"" << std::get<std::string>(it->second) << "\"";
        if(it != std::prev(data.end())) file << ",";
        file <<"\n";
    }
    file << "}\n";
    file.close();
    readJSON();
}

std::string JSONHandler::findValue(const std::string& key) {
    //std::map<std::string, std::variant<std::string, int>> data = readJSON();
    auto it = data.find(key);
    if (it != data.end()) {
        if (std::holds_alternative<std::string>(it->second)) {
            return std::get<std::string>(it->second);
        }
        else if (std::holds_alternative<int>(it->second)) {
            return std::to_string(std::get<int>(it->second));
        }
    }
    return "Not Found";
}

bool JSONHandler::editValue(const std::string& key, const std::string& newValue) {
    std::map<std::string, std::variant<std::string, int>> data = readJSON();
    auto it = data.find(key);
    if (it != data.end()) {
        it->second = newValue;
        writeJSON(data, "");
        return true;
    } else {
        return false;
    }
}

void createDirectories(const std::string& filePath) {
    if (!std::ifstream(filePath).good()) {
        std::filesystem::path path(filePath);
        std::filesystem::create_directories(path.parent_path());
        if (filePath == "C:/ProgramData/WinShareLoc/config/DefaultConfigIPv4.json") {
            JSONHandler json("C:/ProgramData/WinShareLoc/config/DefaultConfigIPv4.json");
            std::map<std::string, std::variant<std::string, int>> configInputIPv4 = {
                {
                    {"IP_Protocol", 4}, 
                    {"Nickname", ""}, 
                    {"Save_Location", "Default Save Location"}, 
                    {"Config", "Default Configuration IPv4"}
                }
            };
            std::map<std::string, std::variant<std::string, int>> configInputIPv6 = {
                {
                    {"IP_Protocol", 6},
                    {"Nickname", ""},
                    {"Save_Location", "Default Save Location"},
                    {"Config", "Default Configuration IPv6"}
                }
            };
            std::map<std::string, std::variant<std::string, int>> InitConfig = {
                {
                    {"language", "en_EN"},
                    {"last_config_used", ""},
                    {"last_location_download", ""},
                    {"last_location_save", ""}
                }
            };
            std::map<std::string, std::variant<std::string, int>> ro_RO = {
                {
                    {"language", "en_EN"},
                    {"last_config_used", ""},
                    {"last_location_download", ""},
                    {"last_location_save", ""}
                }
            };
            json.writeJSON(configInputIPv4, "");
            json.writeJSON(configInputIPv6, "C:/ProgramData/WinShareLoc/config/DefaultConfigIPv6.json");
            json.writeJSON(InitConfig, "C:/ProgramData/WinShareLoc/config/WinShareLocConfigFileDefault.json");
        }
    }
}


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

/*const char* getOS() { //cross platform? Reimplementing this in another way
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&info))) { 
        std::string osString = "MajorVerison: \"" + std::to_string(info.dwMajorVersion) + "\" | MinorVersion\"" + std::to_string(info.dwMinorVersion) + "\""; //for now, only win ver
        char* osCString = new char[osString.length() + 1];
        strcpy(osCString, osString.c_str());
        return osCString;
    } else {
        return "OS undefined"; //if runned on linux||macOS ... also, network functions are cross platform? SHOULD TRY wxWidgets FUNCTIONS.
    }
}*/





BroadcastData setInfo(Status status, const char* type) {
    BroadcastData data;
    const char* username = getLoggedUser();
    const char* desktopName = getDesktopName();
    const char* os = "SAL";//getOS();

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
        case TRANSFERING: return "TRANSFERING";
        default: return "UNKNOWN";
    }
}



/*
int main() {
    JSONHandler jsonHandler("Header Files/MATAexemplu.json");

    std::map<std::string, std::variant<std::string, int>> newData = {
        {
            {"Type", "Transfering"}, 
            {"Nickname", "Asshole"}, 
            {"Desktop_Name", "ScrisManual"},
            {"Desktop_User", "BORHOTU"}, 
            {"Transfer_Port", 2252}, 
            {"IP_Protocol", 6}
        }
    };
    jsonHandler.writeJSON(newData, "");
    return 1;
}*/

/*g++ .\utils.cpp -o main.exe -lws2_32*/