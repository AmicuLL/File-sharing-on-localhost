#include "Header Files/HelpMenu.h"
#include "../BackEnd Source Files/Header Files/utils.h"

Help_AboutDialog::Help_AboutDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(25, 25, 25));

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer(wxHORIZONTAL);

	AboutIco = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./Resource/IconPNG.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(40, 40), 0);
	topSizer->Add(AboutIco, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	appNameLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("appName")), wxDefaultPosition, wxDefaultSize, 0);
	appNameLabel->Wrap(-1);
	appNameLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	appNameLabel->SetForegroundColour(wxColour(122, 32, 72));

	topSizer->Add(appNameLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	LineDivider = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	topSizer->Add(LineDivider, 0, wxALL | wxEXPAND | wxFIXED_MINSIZE, 5);

	wxBoxSizer* buttonAboutSizer;
	buttonAboutSizer = new wxBoxSizer(wxHORIZONTAL);

	buttonAbout = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_aboutTitle")), wxDefaultPosition, wxDefaultSize, 0);
	buttonAbout->SetFont(wxFont(11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Times New Roman")));
	buttonAbout->SetForegroundColour(wxColour(122, 32, 72));
	buttonAbout->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	buttonAboutSizer->Add(buttonAbout, 0, wxALL, 5);

	buttonAuthors = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_authorsTitle")), wxDefaultPosition, wxDefaultSize, 0);
	buttonAuthors->SetFont(wxFont(11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Times New Roman")));
	buttonAuthors->SetForegroundColour(wxColour(122, 32, 72));
	buttonAuthors->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	buttonAboutSizer->Add(buttonAuthors, 0, wxALL, 5);

	buttonLicense = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_licenseTitle")), wxDefaultPosition, wxDefaultSize, 0);
	buttonLicense->SetFont(wxFont(11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Times New Roman")));
	buttonLicense->SetForegroundColour(wxColour(122, 32, 72));
	buttonLicense->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	buttonAboutSizer->Add(buttonLicense, 0, wxALL, 5);

	buttonSoftwareUsed = new wxButton(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_softwareUsedTitle")), wxDefaultPosition, wxDefaultSize, 0);
	buttonSoftwareUsed->SetFont(wxFont(11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Times New Roman")));
	buttonSoftwareUsed->SetForegroundColour(wxColour(122, 32, 72));
	buttonSoftwareUsed->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	buttonAboutSizer->Add(buttonSoftwareUsed, 0, wxALL, 5);


	topSizer->Add(buttonAboutSizer, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


	MainSizer->Add(topSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	TopLineDivider = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	MainSizer->Add(TopLineDivider, 0, wxALL | wxEXPAND, 5);

	labelDisplay = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_aboutTitle")), wxDefaultPosition, wxDefaultSize, 0);
	labelDisplay->Wrap(-1);
	labelDisplay->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	labelDisplay->SetForegroundColour(wxColour(122, 32, 72));

	MainSizer->Add(labelDisplay, 0, wxALIGN_CENTER | wxALL, 5);

	wxBoxSizer* aboutContentSizer;
	aboutContentSizer = new wxBoxSizer(wxVERTICAL);

	aboutContentSizer->SetMinSize(wxSize(600, 200));
	aboutText = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_about_aboutText")), wxDefaultPosition, wxSize(-1, -1), wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxBORDER_NONE);
	aboutText->SetFont(wxFont(8, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Georgia")));
	aboutText->SetForegroundColour(wxColour(250, 200, 200));
	aboutText->SetBackgroundColour(wxColour(25, 25, 25));

	aboutContentSizer->Add(aboutText, 1, wxALL | wxEXPAND, 5);


	MainSizer->Add(aboutContentSizer, 0, 0, 5);


	this->SetSizer(MainSizer);
	this->Layout();

	this->Centre(wxBOTH);
	this->SetTitle(wxString::FromUTF8(getTranslatedData("HELP_about")) + wxT(" ") + wxString::FromUTF8(getTranslatedData("appName")));

	buttonAbout->Bind(wxEVT_BUTTON, &Help_AboutDialog::onButtonAboutClicked, this);
	buttonAuthors->Bind(wxEVT_BUTTON, &Help_AboutDialog::onButtonAuthorsClicked, this);
	buttonLicense->Bind(wxEVT_BUTTON, &Help_AboutDialog::onButtonLicenseClicked, this);
	buttonSoftwareUsed->Bind(wxEVT_BUTTON, &Help_AboutDialog::onButtonSoftwareUsedClicked, this);
}

Help_AboutDialog::~Help_AboutDialog()
{
}

//Event Listeners ABOUT
void Help_AboutDialog::onButtonAboutClicked(wxCommandEvent& event)
{
	labelDisplay->SetLabel(wxString::FromUTF8(getTranslatedData("HELP_about_aboutTitle")));
	//aboutText->SetWindowStyle(wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxBORDER_NONE);
	aboutText->SetValue(wxString::FromUTF8(getTranslatedData("HELP_about_aboutText")));
	this->Layout();
}
void Help_AboutDialog::onButtonAuthorsClicked(wxCommandEvent& event)
{
	labelDisplay->SetLabel(wxString::FromUTF8(getTranslatedData("HELP_about_authorsTitle")));
	//aboutText->SetWindowStyle(wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxBORDER_NONE);
	aboutText->SetValue(wxString::FromUTF8(getTranslatedData("HELP_about_authorsText")));
	this->Layout();
}
void Help_AboutDialog::onButtonLicenseClicked(wxCommandEvent& event)
{
	labelDisplay->SetLabel(wxString::FromUTF8(getTranslatedData("HELP_about_licenseTitle")));
	//aboutText->SetWindowStyle(wxTE_MULTILINE | wxTE_READONLY | wxBORDER_NONE);
	aboutText->SetValue(wxString::FromUTF8(getTranslatedData("HELP_about_licenseText")));
	this->Layout();
}
void Help_AboutDialog::onButtonSoftwareUsedClicked(wxCommandEvent& event)
{
	labelDisplay->SetLabel(wxString::FromUTF8(getTranslatedData("HELP_about_softwareUsedTitle")));
	//aboutText->SetWindowStyle(wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxBORDER_NONE);
	aboutText->SetValue(wxString::FromUTF8(getTranslatedData("HELP_about_softwareUsedText")));
	this->Layout();
}




Help_InstructionsDialog::Help_InstructionsDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(25, 25, 25));

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer(wxHORIZONTAL);

	AboutIco = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./Resource/IconPNG.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(40, 40), 0);
	topSizer->Add(AboutIco, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	appNameLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("appName")), wxDefaultPosition, wxDefaultSize, 0);
	appNameLabel->Wrap(-1);
	appNameLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	appNameLabel->SetForegroundColour(wxColour(122, 32, 72));

	topSizer->Add(appNameLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	LineDivider = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	topSizer->Add(LineDivider, 0, wxALL | wxEXPAND | wxFIXED_MINSIZE, 5);

	displayLabel = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_instructions")), wxDefaultPosition, wxDefaultSize, 0);
	displayLabel->Wrap(-1);
	displayLabel->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	displayLabel->SetForegroundColour(wxColour(122, 32, 72));

	topSizer->Add(displayLabel, 0, wxALIGN_CENTER | wxALL, 5);


	MainSizer->Add(topSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	TopLineDivider = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	MainSizer->Add(TopLineDivider, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* instructionsContentSizer;
	instructionsContentSizer = new wxBoxSizer(wxVERTICAL);

	instructionsContentSizer->SetMinSize(wxSize(600, 200));
	instructionsText = new wxTextCtrl(this, wxID_ANY, wxString::FromUTF8(getTranslatedData("HELP_instructions_text")), wxDefaultPosition, wxSize(-1, -1), wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxBORDER_NONE);
	instructionsText->SetFont(wxFont(8, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Georgia")));
	instructionsText->SetForegroundColour(wxColour(250, 200, 200));
	instructionsText->SetBackgroundColour(wxColour(25, 25, 25));

	instructionsContentSizer->Add(instructionsText, 1, wxALL | wxEXPAND, 5);

	buttonGitHubInstructions = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);

	buttonGitHubInstructions->SetBitmap(wxBitmap(wxT("./Resource/GitHub/github.png"), wxBITMAP_TYPE_ANY));
	buttonGitHubInstructions->SetBitmapFocus(wxBitmap(wxT("./Resource/GitHub/githubSelected.png"), wxBITMAP_TYPE_ANY));
	buttonGitHubInstructions->SetBackgroundColour(wxColour(25, 25, 25));
	
	buttonGitHubInstructions->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) { wxLaunchDefaultBrowser("https://github.com/AmicuLL/File-sharing-on-localhost");});
	
	instructionsContentSizer->Add(buttonGitHubInstructions, 0, wxALIGN_CENTER, 5);


	MainSizer->Add(instructionsContentSizer, 0, wxEXPAND, 5);


	this->SetSizer(MainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

Help_InstructionsDialog::~Help_InstructionsDialog()
{
}