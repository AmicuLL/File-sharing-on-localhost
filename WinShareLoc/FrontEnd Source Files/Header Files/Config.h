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
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include "../../BackEnd Source Files/Header Files/utils.h"

class ConfigurationDialog : public wxDialog
{
private:
	
protected:
	wxStaticText* nameLabel;
	wxTextCtrl* nameInput;
	wxStaticText* ipVerLabel;
	wxChoice* ipVerInput;
	wxStaticText* saveLocLabel;
	wxDirPickerCtrl* saveLocInput;
	wxStaticText* loadConfigLabel;
	wxChoice* loadConfigInput;
	wxButton* buttonApply;
	wxButton* buttonOK;
	wxButton* buttonSaveConf;
	wxButton* buttonCancel;
	void ConfigLanguage();
	void OnShow(wxShowEvent& event);
public:

	ConfigurationDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8(getTranslatedData("CONFIGURATIONS_button")) + wxT(" |") + wxString::FromUTF8(getTranslatedData("appName")), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(490, 225), long style = wxDEFAULT_DIALOG_STYLE);
	void ConfigFile();
	~ConfigurationDialog();

};
