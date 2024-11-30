#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

#include "../../BackEnd Source Files/Header Files/utils.h"

class Help_AboutDialog : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* AboutIco;
		wxStaticText* appNameLabel;
		wxStaticLine* LineDivider;
		wxButton* buttonAbout;
		wxButton* buttonAuthors;
		wxButton* buttonLicense;
		wxButton* buttonSoftwareUsed;
		wxStaticLine* TopLineDivider;
		wxStaticText* labelDisplay;
		wxTextCtrl* aboutText;

	public:

		Help_AboutDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8(getTranslatedData("HELP_about")) + wxT(" ") + wxString::FromUTF8(getTranslatedData("appName")), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 350), long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);

		~Help_AboutDialog();

		void onButtonAboutClicked(wxCommandEvent& event);
		void onButtonAuthorsClicked(wxCommandEvent& event);
		void onButtonLicenseClicked(wxCommandEvent& event);
		void onButtonSoftwareUsedClicked(wxCommandEvent& event);
};


class Help_InstructionsDialog : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* AboutIco;
		wxStaticText* appNameLabel;
		wxStaticLine* LineDivider;
		wxStaticText* displayLabel;
		wxStaticLine* TopLineDivider;
		wxTextCtrl* instructionsText;
		wxButton* buttonGitHubInstructions;

	public:

		Help_InstructionsDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8(getTranslatedData("HELP_instructions")) + wxT(" |") + wxString::FromUTF8(getTranslatedData("appName")), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 310), long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);

		~Help_InstructionsDialog();

};

class HelpMenuDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* ipv4Label;
		wxTextCtrl* nameInput;
		wxStaticText* ipv6Label;
		wxTextCtrl* ipv6Output;
		wxStaticText* nicknameLabel;
		wxTextCtrl* nicknameOutput;
		wxStaticText* configLabel;
		wxTextCtrl* configOutput;
		wxStaticText* connectedLabel;
		wxTextCtrl* connectedOutput;
		wxStaticText* connectedText;
		wxStaticText* transferingText;
		wxStaticText* availableText;

	public:

		HelpMenuDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8(getTranslatedData("INFORMATIONS_button")) + wxT(" |") + wxString::FromUTF8(getTranslatedData("appName")), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(547, 262), long style = wxDEFAULT_DIALOG_STYLE);

		~HelpMenuDialog();

};