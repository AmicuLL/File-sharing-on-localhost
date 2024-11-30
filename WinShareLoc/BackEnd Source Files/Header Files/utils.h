#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <map>
#include <variant>


class JSONHandler {
	public:
        JSONHandler(const std::string& filename);

        std::map<std::string, std::variant<std::string, int>> readJSON();
		void writeJSON(const std::map<std::string, std::variant<std::string, int>>& data, const std::string& filename);
		std::string findValue(const std::string& key);
        bool editValue(const std::string& key, const std::string& newValue);

	private:
		std::string filename;
        std::map<std::string, std::variant<std::string, int>> data;
};
void setLanguage(const std::string&);
JSONHandler getHandler();
std::string getTranslatedData(const std::string&);

void createDirectories(const std::string&);

enum Status {
    AVAILABLE,
    CONNECTED,
    SHARING,
	TRANSFERING
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
//const char* getOS();
BroadcastData setInfo(Status status = AVAILABLE, const char* type = "Info");

std::string statusToString(Status status);

#endif // UTILS_H