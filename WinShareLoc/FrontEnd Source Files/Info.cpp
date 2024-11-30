#include "Header Files/Info.h"

InformationDialog::InformationDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(25, 25, 25));

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* HorizontalSizer;
	HorizontalSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* ipv4Sizer;
	ipv4Sizer = new wxBoxSizer(wxHORIZONTAL);

	ipv4Label = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_IPV4")), wxDefaultPosition, wxDefaultSize, 0);
	ipv4Label->Wrap(-1);
	ipv4Label->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ipv4Label->SetForegroundColour(wxColour(122, 32, 72));

	ipv4Sizer->Add(ipv4Label, 0, wxALL, 5);

	nameInput = new wxTextCtrl(this, wxID_ANY, wxT("192.168.1.135"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER | wxTE_READONLY);
	nameInput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	nameInput->SetForegroundColour(wxColour(122, 32, 72));
	nameInput->SetBackgroundColour(wxColour(25, 25, 25));
	nameInput->SetMinSize(wxSize(360, -1));

	ipv4Sizer->Add(nameInput, 0, wxALL | wxEXPAND, 5);


	HorizontalSizer->Add(ipv4Sizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* ipv6Sizer;
	ipv6Sizer = new wxBoxSizer(wxHORIZONTAL);

	ipv6Label = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_IPV6")), wxDefaultPosition, wxDefaultSize, 0);
	ipv6Label->Wrap(-1);
	ipv6Label->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ipv6Label->SetForegroundColour(wxColour(122, 32, 72));

	ipv6Sizer->Add(ipv6Label, 0, wxALL, 5);

	ipv6Output = new wxTextCtrl(this, wxID_ANY, wxT("2a02:2f0e:309:a700:50ab:f9e6:638c:712f"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER | wxTE_READONLY);
	ipv6Output->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	ipv6Output->SetForegroundColour(wxColour(122, 32, 72));
	ipv6Output->SetBackgroundColour(wxColour(25, 25, 25));
	ipv6Output->SetMinSize(wxSize(360, -1));

	ipv6Sizer->Add(ipv6Output, 0, wxALL | wxEXPAND, 5);


	HorizontalSizer->Add(ipv6Sizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* nicknameSizer;
	nicknameSizer = new wxBoxSizer(wxHORIZONTAL);

	nicknameLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_displayedName")), wxDefaultPosition, wxDefaultSize, 0);
	nicknameLabel->Wrap(-1);
	nicknameLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	nicknameLabel->SetForegroundColour(wxColour(122, 32, 72));

	nicknameSizer->Add(nicknameLabel, 0, wxALL, 5);

	nicknameOutput = new wxTextCtrl(this, wxID_ANY, wxT("Gionutzu"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER | wxTE_READONLY);
	nicknameOutput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	nicknameOutput->SetForegroundColour(wxColour(122, 32, 72));
	nicknameOutput->SetBackgroundColour(wxColour(25, 25, 25));
	nicknameOutput->SetMinSize(wxSize(280, -1));

	nicknameSizer->Add(nicknameOutput, 0, wxALL, 5);


	HorizontalSizer->Add(nicknameSizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* configSizer;
	configSizer = new wxBoxSizer(wxHORIZONTAL);

	configLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_loadedConfig")), wxDefaultPosition, wxDefaultSize, 0);
	configLabel->Wrap(-1);
	configLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	configLabel->SetForegroundColour(wxColour(122, 32, 72));

	configSizer->Add(configLabel, 0, wxALL, 5);

	configOutput = new wxTextCtrl(this, wxID_ANY, wxT("dauHDsiVezi3D.cfg"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER | wxTE_READONLY);
	configOutput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	configOutput->SetForegroundColour(wxColour(122, 32, 72));
	configOutput->SetBackgroundColour(wxColour(25, 25, 25));
	configOutput->SetMinSize(wxSize(350, -1));

	configSizer->Add(configOutput, 0, wxALL, 5);


	HorizontalSizer->Add(configSizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* connectedSizer;
	connectedSizer = new wxBoxSizer(wxHORIZONTAL);

	connectedLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_connectedWith")), wxDefaultPosition, wxDefaultSize, 0);
	connectedLabel->Wrap(-1);
	connectedLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	connectedLabel->SetForegroundColour(wxColour(122, 32, 72));

	connectedSizer->Add(connectedLabel, 0, wxALL, 5);

	connectedOutput = new wxTextCtrl(this, wxID_ANY, wxT("102.168.1.152"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER | wxTE_READONLY);
	connectedOutput->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	connectedOutput->SetForegroundColour(wxColour(122, 32, 72));
	connectedOutput->SetBackgroundColour(wxColour(25, 25, 25));
	connectedOutput->SetMinSize(wxSize(334, -1));

	connectedSizer->Add(connectedOutput, 0, wxALL, 5);


	HorizontalSizer->Add(connectedSizer, 1, wxALIGN_CENTER, 5);

	wxBoxSizer* infoSizer;
	infoSizer = new wxBoxSizer(wxHORIZONTAL);


	infoSizer->Add(0, 0, 1, wxEXPAND, 5);

	connectedText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_isNotConnected")), wxDefaultPosition, wxDefaultSize, 0);
	connectedText->Wrap(-1);
	connectedText->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	connectedText->SetForegroundColour(wxColour(40, 40, 40));

	infoSizer->Add(connectedText, 0, wxALL, 5);


	infoSizer->Add(0, 0, 1, wxEXPAND, 5);

	transferingText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_isNotTransfering")), wxDefaultPosition, wxDefaultSize, 0);
	transferingText->Wrap(-1);
	transferingText->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	transferingText->SetForegroundColour(wxColour(40, 40, 40));

	infoSizer->Add(transferingText, 0, wxALL, 5);


	infoSizer->Add(0, 0, 1, wxEXPAND, 5);

	availableText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("INFO_isAvailable")), wxDefaultPosition, wxDefaultSize, 0);
	availableText->Wrap(-1);
	availableText->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	availableText->SetForegroundColour(wxColour(0, 125, 0));

	infoSizer->Add(availableText, 0, wxALL, 5);


	infoSizer->Add(0, 0, 1, wxEXPAND, 5);


	HorizontalSizer->Add(infoSizer, 1, wxEXPAND, 5);


	MainSizer->Add(HorizontalSizer, 1, wxEXPAND, 5);


	this->SetSizer(MainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	wxIcon appIcon;
	appIcon.LoadFile("./Resource/Icon.ico", wxBITMAP_TYPE_ICO);
	this->SetIcon(appIcon);
}

InformationDialog::~InformationDialog()
{
}
