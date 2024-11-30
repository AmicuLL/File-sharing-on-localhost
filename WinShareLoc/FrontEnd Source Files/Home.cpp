#include "Header Files/Home.h"
#include "MainFrame.h"


void HomeContent(wxStaticText* MenuDisplayer, wxBoxSizer* ContentBoxSizer, wxWindow* parent) {
	wxInitAllImageHandlers();
	wxStaticText* WelcomeLabel;
	wxTextCtrl* ContentText;
	wxButton* ContentButtonGitHub;
	
	ContentBoxSizer->Clear(true);
	WelcomeLabel = new wxStaticText(parent, wxID_ANY, wxT("Welcome to ") + wxString::FromUTF8(getTranslatedData("appName")), wxDefaultPosition, wxDefaultSize, 0);
	WelcomeLabel->Wrap(-1);
	WelcomeLabel->SetFont(wxFont(16, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Bauhaus 93")));
	WelcomeLabel->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

	ContentBoxSizer->Add(WelcomeLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	ContentText = new wxTextCtrl(parent, wxID_ANY, wxString::FromUTF8(getTranslatedData("HOME_text")), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_NOHIDESEL | wxTE_READONLY | wxBORDER_NONE);
	ContentText->SetBackgroundColour( wxColour( 25, 25, 25 ) );
	ContentText->SetFont(wxFont(11, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Californian FB")));
	ContentText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	ContentText->SetMinSize(wxSize(-1, 230));

	ContentBoxSizer->Add(ContentText, 0, wxALL | wxEXPAND, 5);

	ContentButtonGitHub = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTRANSPARENT_WINDOW | wxBORDER_NONE);

	ContentButtonGitHub->SetBitmap(wxBitmap(wxT("./Resource/GitHub/github.png"), wxBITMAP_TYPE_PNG));
	ContentButtonGitHub->SetBitmapFocus(wxBitmap(wxT("./Resource/GitHub/githubSelected.png"), wxBITMAP_TYPE_ANY));
	ContentButtonGitHub->SetBackgroundColour(wxColour(25, 25, 25));
	ContentButtonGitHub->SetMinSize(wxSize(-1, 85));

	ContentButtonGitHub->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) {
		wxLaunchDefaultBrowser(wxT("https://github.com/AmicuLL/File-sharing-on-localhost"));
		});


	MenuDisplayer->SetLabel(wxT("Home Menu"));

	ContentBoxSizer->Add(ContentButtonGitHub, 1, wxALIGN_CENTER | wxALL, 5);
	ContentBoxSizer->Layout();
	parent->Layout();

}