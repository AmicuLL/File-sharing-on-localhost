#include "GUI.h"
#include "NetworkThread.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class ConfigFile {
private:
    std::map<std::string, std::map<std::string, std::string>> ReadINIFile(const std::string& filename) {
        std::map<std::string, std::map<std::string, std::string>> iniData;
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Configuration file: \"" << filename << "\" couldn't be accessed" << std::endl;
            return iniData;
        }

        std::string line;
        std::string currentSection;

        while (std::getline(file, line)) {
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);

            if (!line.empty() && line[0] != ';') {
                if (line[0] == '[' && line[line.length() - 1] == ']') {
                    currentSection = line.substr(1, line.length() - 2);
                }
                else {
                    std::size_t equalsPos = line.find('=');
                    if (equalsPos != std::string::npos) {
                        std::string key = line.substr(0, equalsPos);
                        std::string value = line.substr(equalsPos + 1);
                        iniData[currentSection][key] = value;
                    }
                }
            }
        }

        file.close();
        return iniData;
    }

    void WriteINIFile(const std::string& filename, const std::map<std::string, std::map<std::string, std::string>>& iniData) {
        std::ifstream existingFile(filename);
        
        if (existingFile.good()) {
            std::cout << "Config file: \"" << filename << "\" already exists. No need to overwrite." << std::endl;
            return;
        }
        
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Config file: \"" << filename << "\" occurred an error when creating or opening!" << std::endl;
            return;
        }

        for (const auto& section : iniData) {
            file << "[" << section.first << "]\n";
            for (const auto& entry : section.second) {
                file << entry.first << "=" << entry.second << "\n";
            }
            file << "\n";
        }
        file.close();
    }
    void writeConfig() {
        std::map<std::string, std::map<std::string, std::string>> iniData = ReadINIFile("config.ini");

        iniData["User"]["Name"] = "PREDEFINED";
        iniData["User"]["PORT"] = "271";
        iniData["User"]["BROADCAST_ADDRESS"] = "255.255.255.255";
        iniData["User"]["BROADCAST_INTERVAL"] = "200";
        iniData["User"]["BROADCAST_CHECK_INTERVAL"] = "271";
        iniData["User"]["BROADCAST_CHECK_INTERATIONS"] = "271";
        WriteINIFile("config.ini", iniData);
    }
public: int getPort() {

}
      void writeUserConfig() {
          std::map<std::string, std::map<std::string, std::string>> iniData = ReadINIFile("config.ini");
          const char nume = 'Sal';
          int port = 1234;
          char broadcastAddr = *"255.255.255.255";
          iniData["User"]["Name"] = "\"" + std::to_string(nume) + "\"";
          iniData["User"]["PORT"] = "\"" + std::to_string(port) + "\"";
          iniData["User"]["BROADCAST_ADDRESS"] = "\"" + std::to_string(broadcastAddr) + "\"";
          iniData["User"]["BROADCAST_INTERVAL"] = "200";
          iniData["User"]["BROADCAST_CHECK_INTERVAL"] = "271";
          iniData["User"]["BROADCAST_CHECK_INTERATIONS"] = "271";
          WriteINIFile("config.ini", iniData);
      }
      void readConfig() {

          std::map<std::string, std::map<std::string, std::string>> iniData = ReadINIFile("config.ini");

          if (iniData.find("User") != iniData.end()) {
              std::string name = iniData["User"]["Name"];
              std::string portStr = iniData["User"]["PORT"];
              std::string broadcastAddr = iniData["User"]["BROADCAST_ADDRESS"];

              int port = std::stoi(portStr);

              std::cout << "Nume: " << name << std::endl;
              std::cout << "Port: " << port << std::endl;
              std::cout << "Adresa de broadcast: " << broadcastAddr << std::endl;
          }
          else {
              std::cerr << "Secțiunea 'User' nu a fost găsită\n";
          }
      }
};


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, NetworkThread* networkThread)
    : wxFrame(NULL, wxID_ANY, title, pos, size), networkThread(networkThread) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    label = new wxStaticText(panel, wxID_ANY, "Detecteaza server disponibil...", wxPoint(10, 10));
    button = new wxButton(panel, wxID_ANY, "Click me", wxPoint(10, 50));

    Connect(button->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonClicked));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(label, 0, wxALL, 10);
    sizer->Add(button, 0, wxALL, 10);

    panel->SetSizer(sizer);
    Centre();
}

void MyFrame::OnButtonClicked(wxCommandEvent& event) {
    networkThread->StartBroadcast();//Start();
    //la incarcarea interfatei grafice, ar cam trebui sa porneasca toata jucaria, dar poate sa fie pe un buton de start?
}

