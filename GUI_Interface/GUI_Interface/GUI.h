#pragma once

#include <wx/wx.h>

class NetworkThread;

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, NetworkThread* networkThread);

private:
    void OnButtonClicked(wxCommandEvent& event);
    NetworkThread* networkThread;
    wxStaticText* label;
    wxButton* button;
};
