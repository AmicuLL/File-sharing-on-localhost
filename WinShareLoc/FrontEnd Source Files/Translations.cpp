#include "../BackEnd Source Files/Header Files/utils.h" 

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

void Translation(std::string filePath, std::string key){
    std::cout << JSONHandler(filePath).findValue(key);
}

int main() {
    std::cout << "Sanatate!";
    Translation("C:\\ProgramData\\WinShareLoc\\ro_RO.json", "HELP_STATUS_github");
    return 0;
}