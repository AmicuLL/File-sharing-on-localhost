#include <wx/wx.h>
//#include <wx/taskbar.h>
#include <wx/icon.h>

#include "FrontEnd Source Files/MainFrame.h"
#include "BackEnd Source Files/Header Files/utils.h"
//#include "./BackEnd Source Files/Header Files/init.h"


class MyApp : public wxApp {
public: 
	virtual bool OnInit() override { //1,527kb 1.49MB
		JSONHandler handler("C:\\ProgramData\\WinShareLoc\\config\\WinShareLocConfigFileDefault.json");
		setLanguage(handler.findValue("language"));

		MainFrame* frame = new MainFrame(nullptr);

		wxIcon appIcon;
		appIcon.LoadFile("./Resource/Icon.ico", wxBITMAP_TYPE_ICO);
		frame->SetIcon(appIcon);

		/*wxTaskBarIcon* taskBarIcon = new wxTaskBarIcon();
		wxIcon taskBarIconImage("E:/Programming/C++/WinShareLocGUI/GUI/Resurse/Icon.ico", wxBITMAP_TYPE_ICO);
		taskBarIcon->SetIcon(taskBarIconImage, "Tooltip pentru pictograma");*/

		return frame->Show();
	}
};
wxIMPLEMENT_APP(MyApp);