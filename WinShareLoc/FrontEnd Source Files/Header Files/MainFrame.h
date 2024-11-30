#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/grid.h>

#include "Header Files/Info.h"
#include "Header Files/HelpMenu.h"
#include "Header Files/Config.h"

#include "../BackEnd Source Files/Header Files/utils.h"

class MainFrame : public wxFrame
{
private:
	wxMenuBar* MenuBar;
	wxMenu* FileMenu;
	wxMenu* HelpMenu;
	wxMenu* LanguageMenu;
	wxStatusBar* StatusBar;
	wxButton* ButtonHome;
	wxButton* ButtonTransfer;
	wxButton* ButtonConfig;
	wxButton* ButtonChat;
	wxButton* ButtonInformations;
	wxStaticLine* MainBoxSeparator;
	wxStaticText* MenuDisplayer;
	wxStaticLine* MainBoxSeparator1;

	Help_AboutDialog* AboutDialog;
	Help_InstructionsDialog* InstructionsDialog;
	ConfigurationDialog* ConfDialog;
	InformationDialog* InfoDialog;
	
	void LoadTranslations(const wxString& language);

public:
	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8(getTranslatedData("appName")) + wxT(" | Windows Share Local Files"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	void OnChangeLanguage(wxString language);
	void OnKeyDown(wxKeyEvent& event);
	~MainFrame();

};

