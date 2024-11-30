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

#include "../../BackEnd Source Files/Header Files/utils.h"

class InformationDialog : public wxDialog
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

	InformationDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Info |") + wxString::FromUTF8(getTranslatedData("appName")), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(547, 262), long style = wxDEFAULT_DIALOG_STYLE);

	~InformationDialog();

};

