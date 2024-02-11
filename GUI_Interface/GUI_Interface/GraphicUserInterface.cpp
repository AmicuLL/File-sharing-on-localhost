#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
    {
        // Creeaza un panou pentru a contine controalele
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        // Adauga butoanele si zona de lista
        wxButton* btnConnect = new wxButton(panel, wxID_ANY, wxT("Connect"), wxPoint(10, 10));
        wxButton* btnExit = new wxButton(panel, wxID_ANY, wxT("Exit"), wxPoint(100, 10));
        wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 50), wxSize(200, 150));

        // Conecteaza evenimentul de click pentru butonul "Connect"
        btnConnect->Bind(wxEVT_BUTTON, &MyFrame::OnConnect, this);
        // Conecteaza evenimentul de click pentru butonul "Exit"
        btnExit->Bind(wxEVT_BUTTON, &MyFrame::OnExit, this);

        // Adauga elemente de exemplu in lista
        listBox->Append(wxT("Item 1"));
        listBox->Append(wxT("Item 2"));
        listBox->Append(wxT("Item 3"));
    }

    // Functie apelata la apasarea butonului "Connect"
    void OnConnect(wxCommandEvent& event)
    {
        // Aici poti adauga cod pentru actiunile asociate butonului "Connect"
        wxMessageBox(wxT("Connect button clicked!"));
    }

    // Functie apelata la apasarea butonului "Exit"
    void OnExit(wxCommandEvent& event)
    {
        // Inchide fereastra
        Close(true);
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame(wxT("My App"), wxPoint(50, 50), wxSize(300, 250));
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
