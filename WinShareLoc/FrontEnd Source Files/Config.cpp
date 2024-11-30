#include "Header Files/Config.h"
#include <wx/log.h>
#include <wx/stdpaths.h>

ConfigurationDialog::ConfigurationDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(25, 25, 25));

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* HorizontalSizer;
	HorizontalSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* nameSizer;
	nameSizer = new wxBoxSizer(wxHORIZONTAL);

	nameLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	nameLabel->Wrap(-1);
	nameLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	nameLabel->SetForegroundColour(wxColour(122, 32, 72));
	
	nameSizer->Add(nameLabel, 0, wxALL, 5);

	nameInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	nameInput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	nameInput->SetForegroundColour(wxColour(122, 32, 72));
	nameInput->SetBackgroundColour(wxColour(25, 25, 25));
	nameInput->SetMinSize(wxSize(150, -1));

	nameSizer->Add(nameInput, 0, wxALL | wxEXPAND, 5);


	HorizontalSizer->Add(nameSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* ipProtSizer;
	ipProtSizer = new wxBoxSizer(wxHORIZONTAL);

	ipVerLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	ipVerLabel->Wrap(-1);
	ipVerLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ipVerLabel->SetForegroundColour(wxColour(122, 32, 72));

	ipProtSizer->Add(ipVerLabel, 0, wxALL, 5);

	wxString ipVerInputChoices[] = { wxT("IPv4"), wxT("IPv6") };
	int ipVerInputNChoices = sizeof(ipVerInputChoices) / sizeof(wxString);
	ipVerInput = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ipVerInputNChoices, ipVerInputChoices, 0);
	ipVerInput->SetSelection(0);
	ipVerInput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold Condensed")));
	ipVerInput->SetForegroundColour(wxColour(122, 32, 72));
	ipVerInput->SetBackgroundColour(wxColour(25, 25, 25));

	ipProtSizer->Add(ipVerInput, 0, wxALL, 5);


	HorizontalSizer->Add(ipProtSizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* locationSizer;
	locationSizer = new wxBoxSizer(wxHORIZONTAL);

	saveLocLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	saveLocLabel->Wrap(-1);
	saveLocLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	saveLocLabel->SetForegroundColour(wxColour(122, 32, 72));

	locationSizer->Add(saveLocLabel, 0, wxALL, 5);

	saveLocInput = new wxDirPickerCtrl(this, wxID_ANY, wxT("Downloads"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE);
	saveLocInput->SetForegroundColour(wxColour(122, 32, 72));
	saveLocInput->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));

	locationSizer->Add(saveLocInput, 0, wxALL | wxEXPAND, 5);


	HorizontalSizer->Add(locationSizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* configSizer;
	configSizer = new wxBoxSizer(wxHORIZONTAL);

	loadConfigLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	loadConfigLabel->Wrap(-1);
	loadConfigLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	loadConfigLabel->SetForegroundColour(wxColour(122, 32, 72));

	configSizer->Add(loadConfigLabel, 0, wxALL, 5);

	wxString loadConfigInputChoices[] = { wxT("DefaultConfigIPv4"), wxT("DefaultConfigIPv6"), wxT("Config 2") };
	int loadConfigInputNChoices = sizeof(loadConfigInputChoices) / sizeof(wxString);
	loadConfigInput = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, loadConfigInputNChoices, loadConfigInputChoices, wxCB_SORT);
	loadConfigInput->SetSelection(0);
	loadConfigInput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold Condensed")));
	loadConfigInput->SetForegroundColour(wxColour(122, 32, 72));
	loadConfigInput->SetBackgroundColour(wxColour(25, 25, 25));

	configSizer->Add(loadConfigInput, 0, wxALL, 5);


	HorizontalSizer->Add(configSizer, 1, wxALIGN_CENTER, 5);


	MainSizer->Add(HorizontalSizer, 1, wxEXPAND, 5);

	wxBoxSizer* Buttons;
	Buttons = new wxBoxSizer(wxHORIZONTAL);

	buttonApply = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	buttonApply->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	buttonApply->SetForegroundColour(wxColour(122, 32, 72));
	buttonApply->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	Buttons->Add(buttonApply, 0, wxALL, 5);

	buttonOK = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	buttonOK->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	buttonOK->SetForegroundColour(wxColour(122, 32, 72));
	buttonOK->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	Buttons->Add(buttonOK, 0, wxALL, 5);

	buttonSaveConf = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	buttonSaveConf->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	buttonSaveConf->SetForegroundColour(wxColour(122, 32, 72));
	buttonSaveConf->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	Buttons->Add(buttonSaveConf, 0, wxALL, 5);

	buttonCancel = new wxButton(this, wxID_ANY,  wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	buttonCancel->SetFont(wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	buttonCancel->SetForegroundColour(wxColour(122, 32, 72));
	buttonCancel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	Buttons->Add(buttonCancel, 0, wxALL, 5);


	MainSizer->Add(Buttons, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	this->SetSizer(MainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	buttonCancel->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { //Cancel Button
		Close(true);
		});

	wxIcon appIcon;
	appIcon.LoadFile("./Resource/Icon.ico", wxBITMAP_TYPE_ICO);
	this->SetIcon(appIcon);

	Bind(wxEVT_SHOW, &ConfigurationDialog::OnShow, this);
}

ConfigurationDialog::~ConfigurationDialog()
{
}

void ConfigurationDialog::ConfigFile() {
	createDirectories("C:/ProgramData/WinShareLoc/config/DefaultConfigIPv4.json");
	JSONHandler json("C:/ProgramData/WinShareLoc/config/DefaultConfigIPv4.json");
	nameInput->SetValue(json.findValue("Nickname") == "" ? "WinShareLoc" : json.findValue("Nickname"));
	ipVerInput->SetSelection(std::stoi(json.findValue("IP_Protocol")) == 4 ? 0 : std::stoi(json.findValue("IP_Protocol")) == 6 ? 1 : 0);
	saveLocInput->SetPath(json.findValue("Save_Location") == "Default Save Location" ? wxStandardPaths::Get().GetUserDir(wxStandardPaths::Dir::Dir_Downloads) : json.findValue("Save_Location"));
}

void ConfigurationDialog::ConfigLanguage() {
	nameLabel->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_nickname")));
	ipVerLabel->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_IPProtVer")));
	saveLocLabel->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_saveDest")));
	loadConfigLabel->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_loadConfig")));
	buttonApply->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_apply")));
	buttonOK->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_OK")));
	buttonSaveConf->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_saveConfig")));
	buttonCancel->SetLabel(wxString::FromUTF8(getTranslatedData("CONFIG_cancel")));
	this->SetTitle(wxString::FromUTF8(getTranslatedData("CONFIGURATIONS_button")) + wxT(" |") + wxString::FromUTF8(getTranslatedData("appName")));
	this->Layout();
}

void ConfigurationDialog::OnShow(wxShowEvent& event)
{
	if (event.IsShown())
	{
		ConfigLanguage();
		ConfigFile();
	}
	event.Skip();
}
