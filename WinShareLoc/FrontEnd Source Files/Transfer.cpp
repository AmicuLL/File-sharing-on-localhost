#include "Header Files/Transfer.h"
#include "MainFrame.h"

void TransferContent(wxStaticText* MenuDisplayer, wxBoxSizer* ContentBoxSizer, wxWindow* parent) {
	wxInitAllImageHandlers();
	wxButton* TransferButtonUploadsSelect;
	wxButton* TransferButtonDownloadsSelect;
	wxButton* TransferButtonUpload;
	wxButton* TransferButtonDisconnect;
	wxButton* TransferButtonResume;
	wxButton* TransferButtonPause;
	wxButton* TransferButtonStop;
	wxStaticLine* ContentBoxSeparator;
	wxGrid* TableTransfer;


	ContentBoxSizer->Clear(true);

	wxBoxSizer* ButtonTransferBoxSizer;
	ButtonTransferBoxSizer = new wxBoxSizer(wxHORIZONTAL);
	ButtonTransferBoxSizer->SetMinSize(wxSize(-1, 30));

	TransferButtonUploadsSelect = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxBU_EXACTFIT);

	TransferButtonUploadsSelect->SetBitmap(wxBitmap(wxT("./Resource/Downloads/downloadsUnfocusedVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonUploadsSelect->SetBitmapPressed(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonUploadsSelect->SetBitmapFocus(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonUploadsSelect->SetBitmapCurrent(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonUploadsSelect, 0, wxALL, 5);

	TransferButtonDownloadsSelect = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxBU_EXACTFIT);

	TransferButtonDownloadsSelect->SetBitmap(wxBitmap(wxT("./Resource/Downloads/downloadsSelectedVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonDownloadsSelect->SetBitmapPressed(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonDownloadsSelect->SetBitmapFocus(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	TransferButtonDownloadsSelect->SetBitmapCurrent(wxBitmap(wxT("./Resource/Uploads/uploadsVerySmall.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonDownloadsSelect, 0, wxALL, 5);


	ButtonTransferBoxSizer->Add(90, 0, 1, wxEXPAND, 5);

	TransferButtonUpload = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(80, 20), 0);

	TransferButtonUpload->SetBitmap(wxBitmap(wxT("./Resource/Controls/sendMic.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonUpload, 0, wxALL, 5);

	TransferButtonDisconnect = new wxButton(parent, wxID_ANY, wxT("Disconnect"), wxDefaultPosition, wxSize(-1, 20), wxBU_EXACTFIT);

	TransferButtonDisconnect->SetBitmap(wxBitmap(wxT("./Resource/Controls/Disconnect.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonDisconnect, 0, wxALL, 5);


	ButtonTransferBoxSizer->Add(60, 0, 1, wxEXPAND, 5);

	TransferButtonResume = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, 20), wxBU_EXACTFIT);

	TransferButtonResume->SetBitmap(wxBitmap(wxT("./Resource/Controls/resume20x20.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonResume, 0, wxALL, 5);

	TransferButtonPause = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, 20), wxBU_EXACTFIT);

	TransferButtonPause->SetBitmap(wxBitmap(wxT("./Resource/Controls/pause20x20.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonPause, 0, wxALL, 5);

	TransferButtonStop = new wxButton(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, 20), wxBU_EXACTFIT);

	TransferButtonStop->SetBitmap(wxBitmap(wxT("./Resource/Controls/stop20x20.png"), wxBITMAP_TYPE_ANY));
	ButtonTransferBoxSizer->Add(TransferButtonStop, 0, wxALL, 5);


	ContentBoxSizer->Add(ButtonTransferBoxSizer, 0, wxEXPAND, 5);

	ContentBoxSeparator = new wxStaticLine(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	ContentBoxSizer->Add(ContentBoxSeparator, 0, wxEXPAND | wxALL, 5);

	TableTransfer = new wxGrid(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	TableTransfer->CreateGrid(20, 5);
	TableTransfer->EnableEditing(false);
	TableTransfer->EnableGridLines(true);
	TableTransfer->SetGridLineColour(wxColour(122, 32, 72));
	TableTransfer->EnableDragGridSize(false);
	TableTransfer->SetMargins(0, 0);

	// Columns
	TableTransfer->SetColSize(0, 220);
	TableTransfer->SetColSize(1, 220);
	TableTransfer->SetColSize(2, 120);
	TableTransfer->SetColSize(3, 170);
	TableTransfer->SetColSize(4, 200);
	TableTransfer->EnableDragColMove(true);
	TableTransfer->EnableDragColSize(true);
	TableTransfer->SetColLabelValue(0, wxT("FilePath"));
	TableTransfer->SetColLabelValue(1, wxT("Size"));
	TableTransfer->SetColLabelValue(2, wxT("Status"));
	TableTransfer->SetColLabelValue(3, wxT("Progress"));
	TableTransfer->SetColLabelValue(4, wxT("Command"));
	TableTransfer->SetColLabelSize(20);
	TableTransfer->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	TableTransfer->SetRowSize(0, 20);
	TableTransfer->AutoSizeRows();
	TableTransfer->EnableDragRowSize(false);
	TableTransfer->SetRowLabelSize(wxGRID_AUTOSIZE);
	TableTransfer->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance
	TableTransfer->SetLabelBackgroundColour(wxColour(255, 193, 194));
	TableTransfer->SetLabelFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Gill Sans Ultra Bold")));
	TableTransfer->SetLabelTextColour(wxColour(122, 32, 72));

	// Cell Defaults
	TableTransfer->SetDefaultCellBackgroundColour(wxColour(25, 25, 25));
	TableTransfer->SetDefaultCellTextColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	TableTransfer->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	TableTransfer->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	TableTransfer->SetBackgroundColour(wxColour(25, 25, 25));
	TableTransfer->SetMinSize(wxSize(980, -1));

	MenuDisplayer->SetLabel(wxT("Transfer Menu"));
	ContentBoxSizer->Add(TableTransfer, 0, wxEXPAND | wxALL, 5);
	ContentBoxSizer->Layout();
	parent->Layout();
}