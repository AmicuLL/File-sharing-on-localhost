#include "Header Files/MainFrame.h"
#include "Header Files/Home.h"
#include "Header Files/Transfer.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(25, 25, 25));

	MenuBar = new wxMenuBar(0);
	FileMenu = new wxMenu();
	wxMenuItem* FileMenu_NewConnection;
	FileMenu_NewConnection = new wxMenuItem(FileMenu, 10, wxString::FromUTF8(getTranslatedData("FILE_new_Connection")) + wxT('\t') + wxT("Ctrl + N"), wxString::FromUTF8(getTranslatedData("FILE_STATUS_new_connection")), wxITEM_NORMAL);
	FileMenu->Append(FileMenu_NewConnection);
	
	wxMenuItem* FileMenu_CloseCurrentConnection;
	FileMenu_CloseCurrentConnection = new wxMenuItem(FileMenu, 11, wxString::FromUTF8(getTranslatedData("FILE_close_connection")) + wxT('\t') + wxT("Ctrl + X"), wxString::FromUTF8(getTranslatedData("FILE_STATUS_close_connection")), wxITEM_NORMAL);
	FileMenu->Append(FileMenu_CloseCurrentConnection);

	FileMenu->AppendSeparator();

	wxMenuItem* FileMenu_Config;
	FileMenu_Config = new wxMenuItem(FileMenu, 12, wxString::FromUTF8(getTranslatedData("FILE_configurations")), wxString::FromUTF8(getTranslatedData("FILE_STATUS_configurations")), wxITEM_NORMAL);
	FileMenu->Append(FileMenu_Config);

	wxMenuItem* FileMenu_LoadConfig;
	FileMenu_LoadConfig = new wxMenuItem(FileMenu, 13, wxString::FromUTF8(getTranslatedData("FILE_load_config")), wxString::FromUTF8(getTranslatedData("FILE_STATUS_load_config")), wxITEM_NORMAL);
	FileMenu->Append(FileMenu_LoadConfig);

	FileMenu->AppendSeparator();

	wxMenuItem* FileMenu_Quit;
	FileMenu_Quit = new wxMenuItem(FileMenu, 14, wxString::FromUTF8(getTranslatedData("FILE_exit")) + wxT('\t') + wxT("Alt + F4"), wxString::FromUTF8(getTranslatedData("FILE_STATUS_exit")), wxITEM_NORMAL);
	FileMenu->Append(FileMenu_Quit);

	MenuBar->Append(FileMenu, wxString::FromUTF8(getTranslatedData("file")));

	HelpMenu = new wxMenu();
	wxMenuItem* HelpMenu_Instructions;
	HelpMenu_Instructions = new wxMenuItem(HelpMenu, 20, wxString::FromUTF8(getTranslatedData("HELP_instructions")), wxString::FromUTF8(getTranslatedData("HELP_STATUS_instructions")), wxITEM_NORMAL);
	HelpMenu->Append(HelpMenu_Instructions);

	wxMenuItem* HelpMenu_Help;
	HelpMenu_Help = new wxMenuItem(HelpMenu, 21, wxString::FromUTF8(getTranslatedData("HELP_help")) + wxT('\t') + wxT("F1"), wxString::FromUTF8(getTranslatedData("HELP_STATUS_help")), wxITEM_NORMAL);
	HelpMenu->Append(HelpMenu_Help);

	HelpMenu->AppendSeparator();

	wxMenuItem* HelpMenu_GitHub;
	HelpMenu_GitHub = new wxMenuItem(HelpMenu, 22, wxString::FromUTF8(getTranslatedData("HELP_github")), wxString::FromUTF8(getTranslatedData("HELP_STATUS_github")), wxITEM_NORMAL);
	HelpMenu->Append(HelpMenu_GitHub);

	wxMenuItem* HelpMenu_About;
	HelpMenu_About = new wxMenuItem(HelpMenu, 23, wxString::FromUTF8(getTranslatedData("HELP_about")) + wxT('\t') + wxT("Shift + F1"), wxString::FromUTF8(getTranslatedData("HELP_STATUS_about")), wxITEM_NORMAL);
	HelpMenu->Append(HelpMenu_About);

	MenuBar->Append(HelpMenu, wxString::FromUTF8(getTranslatedData("help")));

	LanguageMenu = new wxMenu();
	wxMenuItem* LanguageMenu_English;
	LanguageMenu_English = new wxMenuItem(LanguageMenu, 30, wxString::FromUTF8(getTranslatedData("english")), wxString::FromUTF8(getTranslatedData("languageInfoEnglish")), wxITEM_NORMAL);
	LanguageMenu->Append(LanguageMenu_English); //id to english == 677622
	
	wxMenuItem* LanguageMenu_Romana;
	LanguageMenu_Romana = new wxMenuItem(LanguageMenu, 31, wxString::FromUTF8(getTranslatedData("romanian")), wxString::FromUTF8(getTranslatedData("languageInfoRomanian")), wxITEM_NORMAL);
	LanguageMenu->Append(LanguageMenu_Romana);

	MenuBar->Append(LanguageMenu, wxString::FromUTF8(getTranslatedData("language")));

	this->SetMenuBar(MenuBar);

	StatusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);
	StatusBar->SetBackgroundColour(wxColour(35, 60, 90));
	//StatusBar->SetFont(StatusBar->GetFont().Bold());
	StatusBar->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));

	wxBoxSizer* MainBoxSizer;
	MainBoxSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* ButtonBoxSizer;
	ButtonBoxSizer = new wxBoxSizer(wxHORIZONTAL);

	ButtonHome = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HOME_button")), wxDefaultPosition, wxDefaultSize, 0);
	ButtonHome->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ButtonHome->SetForegroundColour(wxColour(122, 32, 72));
	ButtonHome->SetBackgroundColour(wxColour(206, 230, 242));
	//ButtonHome->SetToolTip(wxT("Homepage for this particular app"));

	ButtonBoxSizer->Add(ButtonHome, 0, wxALL, 5);

	ButtonTransfer = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("TRANSFER_button")), wxDefaultPosition, wxDefaultSize, 0);
	ButtonTransfer->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ButtonTransfer->SetForegroundColour(wxColour(122, 32, 72));
	ButtonTransfer->SetBackgroundColour(wxColour(206, 230, 242));

	ButtonBoxSizer->Add(ButtonTransfer, 0, wxALL, 5);

	ButtonConfig = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("CONFIGURATIONS_button")), wxDefaultPosition, wxDefaultSize, 0);
	ButtonConfig->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ButtonConfig->SetForegroundColour(wxColour(122, 32, 72));
	ButtonConfig->SetBackgroundColour(wxColour(206, 232, 240));

	ButtonBoxSizer->Add(ButtonConfig, 0, wxALL, 5);
	/*
	ButtonChat = new wxButton(this, wxID_ANY, wxT("CHAT"), wxDefaultPosition, wxDefaultSize, 0);
	ButtonChat->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ButtonChat->SetForegroundColour(wxColour(122, 32, 72));
	ButtonChat->SetBackgroundColour(wxColour(206, 230, 242));

	ButtonBoxSizer->Add(ButtonChat, 0, wxALL, 5);
	*/
	ButtonInformations = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFORMATIONS_button")), wxDefaultPosition, wxDefaultSize, 0);
	ButtonInformations->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ButtonInformations->SetForegroundColour(wxColour(122, 32, 72));
	ButtonInformations->SetBackgroundColour(wxColour(206, 230, 242));

	ButtonBoxSizer->Add(ButtonInformations, 0, wxALL, 5);


	MainBoxSizer->Add(ButtonBoxSizer, 0, wxALIGN_CENTER, 5);

	MainBoxSeparator = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	MainBoxSizer->Add(MainBoxSeparator, 0, wxEXPAND | wxALL, 5);

	MenuDisplayer = new wxStaticText(this, wxID_ANY, wxT("Displayer"), wxDefaultPosition, wxDefaultSize, 0);
	MenuDisplayer->Wrap(-1);
	MenuDisplayer->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	MenuDisplayer->SetForegroundColour(wxColour(120, 150, 170));

	MainBoxSizer->Add(MenuDisplayer, 0, wxALIGN_CENTER | wxALL, 5);

	MainBoxSeparator1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	MainBoxSizer->Add(MainBoxSeparator1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* ContentBoxSizer;
	ContentBoxSizer = new wxBoxSizer(wxVERTICAL);

	HomeContent(MenuDisplayer, ContentBoxSizer, this);

	MainBoxSizer->Add(ContentBoxSizer, 1, wxEXPAND, 5);

	this->SetSizer(MainBoxSizer);
	this->Layout();

	this->Centre(wxBOTH);

	AboutDialog = new Help_AboutDialog(this);
	InstructionsDialog = new Help_InstructionsDialog(this);

	ConfDialog = new ConfigurationDialog(this);
	InfoDialog = new InformationDialog(this);
	//Help_HelpDialog  HelpDialog = new Help_HelpDialog(this);

	ButtonHome->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { //Main Buttons Home
		HomeContent(MenuDisplayer, ContentBoxSizer, this);
		});
	ButtonTransfer->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { //Main Buttons Transfer
		TransferContent(MenuDisplayer, ContentBoxSizer, this);
		});
	ButtonConfig->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { //Main Buttons Config
		ConfDialog->Show();
		ConfDialog->ConfigFile();
		});
	ButtonInformations->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { //Main Buttons Informations
		InfoDialog->Show();
		});
	
	Bind(wxEVT_MENU, [this](wxCommandEvent& event) {//FileMenu Quit
		Close(true);
		}, FileMenu_Quit->GetId());
	Bind(wxEVT_MENU, [=](wxCommandEvent& event) {//FileMenu Config
		ConfDialog->Show();
		ConfDialog->ConfigFile();
		}, FileMenu_Config->GetId());

	Bind(wxEVT_MENU, [this](wxCommandEvent& event) {//HelpMenu Github
		wxLaunchDefaultBrowser("https://github.com/AmicuLL/File-sharing-on-localhost");
		}, HelpMenu_GitHub->GetId());
	Bind(wxEVT_MENU, [=](wxCommandEvent& event) {//HelpMenu About
		AboutDialog->Show();
		}, HelpMenu_About->GetId());
	Bind(wxEVT_MENU, [=](wxCommandEvent& event) {//HelpMenu Instructions
		InstructionsDialog->Show();
		}, HelpMenu_Instructions->GetId());
	Bind(wxEVT_MENU, [this](wxCommandEvent& event) {//HelpMenu Help (F1)
		//HelpDialog->Show();
		}, HelpMenu_Help->GetId());
	Bind(wxEVT_KEY_DOWN, [=](wxKeyEvent& event) { // Listener pentru tastatura
		if (event.GetKeyCode() == WXK_F1) { //Shift + F1
			AboutDialog->Show();
		}
		event.Skip();
		});

	Bind(wxEVT_MENU, [this](wxCommandEvent& event) {//Language set to English
		OnChangeLanguage(wxEmptyString);
		}, LanguageMenu_English->GetId());
	Bind(wxEVT_MENU, [this](wxCommandEvent& event) {//Language set to Romanian
		OnChangeLanguage("ro_RO");
		}, LanguageMenu_Romana->GetId());

	this->SetWindowStyleFlag(this->GetWindowStyleFlag() | wxWANTS_CHARS);
	this->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyDown, this);
}
MainFrame::~MainFrame()
{
}

void MainFrame::OnKeyDown(wxKeyEvent& event)
{
	if (event.ShiftDown() && event.GetKeyCode() == WXK_F1) { //Shift + F1 (About)
		if (AboutDialog->IsShown()) { 
			AboutDialog->Close(); 
		}
		else {
			AboutDialog->Show();
		}
	}
	if (event.AltDown() && event.GetKeyCode() == WXK_F1) { //Alt + F1 (Instructions)
		wxMessageBox(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
		InstructionsDialog->Show();
	}

	if (event.GetKeyCode() == WXK_F1) { //F1 (Help)
		//HelpDialog->Show();
	}
	if (event.ControlDown() && event.GetKeyCode() == 'N') { //CTRL + N (New Connection)
		wxMessageBox(wxString::Format("CTRL + N (New Connection) | KeyDown: %i\n", (int)event.GetKeyCode()));
	}
	if (event.ControlDown() && event.GetKeyCode() == 'X') { //CTRL + X (Close Connection)
		wxMessageBox(wxString::Format("CTRL + X (Close Connection) | KeyDown: %i\n", (int)event.GetKeyCode()));
	}
	event.Skip();
}

void MainFrame::OnChangeLanguage(wxString language) {
	language == "ro_RO" ? setLanguage("ro_RO") : setLanguage("en_EN");
	JSONHandler("C:\\ProgramData\\WinShareLoc\\config\\WinShareLocConfigFileDefault.json").editValue("language", language == "ro_RO" ? "ro_RO" : "en_EN");
	if (AboutDialog->IsShown()) {
		AboutDialog->Hide();
		AboutDialog->Show();
	}
	if (ConfDialog->IsShown()) {
		ConfDialog->Hide();
		ConfDialog->Show();
	}
	if (InfoDialog->IsShown()) {
		InfoDialog->Hide();
		InfoDialog->Show();
	}
	if (InstructionsDialog->IsShown()) {
		InstructionsDialog->Hide();
		InstructionsDialog->Show();
	}
	
	//File
	MenuBar->SetMenuLabel(0, wxString::FromUTF8(getTranslatedData("file")));
		//New Connection
		FileMenu->SetLabel(10, wxString::FromUTF8(getTranslatedData("FILE_new_Connection")));
		FileMenu->SetHelpString(10, wxString::FromUTF8(getTranslatedData("FILE_STATUS_new_connection")));
		//Close Connection
		FileMenu->SetLabel(11, wxString::FromUTF8(getTranslatedData("FILE_close_connection")));
		FileMenu->SetHelpString(11, wxString::FromUTF8(getTranslatedData("FILE_STATUS_close_connection")));
		//Configurations
		FileMenu->SetLabel(12, wxString::FromUTF8(getTranslatedData("FILE_configurations")));
		FileMenu->SetHelpString(12, wxString::FromUTF8(getTranslatedData("FILE_STATUS_configurations")));
		//Load Config
		FileMenu->SetLabel(13, wxString::FromUTF8(getTranslatedData("FILE_load_config")));
		FileMenu->SetHelpString(13, wxString::FromUTF8(getTranslatedData("FILE_STATUS_load_config")));
		//Quit
		FileMenu->SetLabel(14, wxString::FromUTF8(getTranslatedData("FILE_exit")));
		FileMenu->SetHelpString(14, wxString::FromUTF8(getTranslatedData("FILE_STATUS_exit")));

	//Help
	MenuBar->SetMenuLabel(1, wxString::FromUTF8(getTranslatedData("help")));
		//Instructions
		HelpMenu->SetLabel(20, wxString::FromUTF8(getTranslatedData("HELP_instructions")));
		HelpMenu->SetHelpString(20, wxString::FromUTF8(getTranslatedData("HELP_STATUS_instructions")));
		//Help
		HelpMenu->SetLabel(21, wxString::FromUTF8(getTranslatedData("HELP_help")));
		HelpMenu->SetHelpString(21, wxString::FromUTF8(getTranslatedData("HELP_STATUS_help")));
		//Github
		HelpMenu->SetLabel(22, wxString::FromUTF8(getTranslatedData("HELP_github")));
		HelpMenu->SetHelpString(22, wxString::FromUTF8(getTranslatedData("HELP_STATUS_github")));
		//About
		HelpMenu->SetLabel(23, wxString::FromUTF8(getTranslatedData("HELP_about")));
		HelpMenu->SetHelpString(23, wxString::FromUTF8(getTranslatedData("HELP_STATUS_about")));

	//Language
	MenuBar->SetMenuLabel(2, wxString::FromUTF8(getTranslatedData("language")));
		//English
		LanguageMenu->SetLabel(30, wxString::FromUTF8(getTranslatedData("english")));
		LanguageMenu->SetHelpString(30, wxString::FromUTF8(getTranslatedData("languageInfoEnglish")));
		//Romanian
		LanguageMenu->SetLabel(31, wxString::FromUTF8(getTranslatedData("romanian")));
		LanguageMenu->SetHelpString(31, wxString::FromUTF8(getTranslatedData("languageInfoRomanian")));

	//Home Button
	ButtonHome->SetLabel(wxString::FromUTF8(getTranslatedData("HOME_button")));
	//Transfer Button
	ButtonTransfer->SetLabel(wxString::FromUTF8(getTranslatedData("TRANSFER_button")));
	//Configuration Button
	ButtonConfig->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIGURATIONS_button")));
	//Informations Button
	ButtonInformations->SetLabel(wxString::FromUTF8(getTranslatedData("INFORMATIONS_button")));
	this->Layout();
}