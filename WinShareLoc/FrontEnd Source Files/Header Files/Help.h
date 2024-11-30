#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

class HelpAboutDialog : public wxDialog
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

		HelpAboutDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Info Dialog |WinShareLoc"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(547, 262), long style = wxDEFAULT_DIALOG_STYLE);

		~HelpAboutDialog();

};

class HelpInstructionsDialog : public wxDialog
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

		HelpInstructionsDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Info Dialog |WinShareLoc"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(547, 262), long style = wxDEFAULT_DIALOG_STYLE);

		~HelpInstructionsDialog();

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

		HelpMenuDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Info Dialog |WinShareLoc"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(547, 262), long style = wxDEFAULT_DIALOG_STYLE);

		~HelpMenuDialog();

};