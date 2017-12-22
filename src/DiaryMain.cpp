/***************************************************************
 * Name:      DiaryMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-04-08
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "DiaryMain.h"
#include <wx/msgdlg.h>

#include <fstream>
#include <string>

using namespace std;

//(*InternalHeaders(DiaryFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)





//(*IdInit(DiaryFrame)
const long DiaryFrame::ID_GENERICDIRCTRL1 = wxNewId();
const long DiaryFrame::ID_PANEL1 = wxNewId();
const long DiaryFrame::ID_EditorsAUINBook = wxNewId();
const long DiaryFrame::ID_SaveMItem = wxNewId();
const long DiaryFrame::ID_NewFile = wxNewId();
const long DiaryFrame::ID_MENUITEM1 = wxNewId();
const long DiaryFrame::ID_ChangeFont = wxNewId();
const long DiaryFrame::idMenuAbout = wxNewId();
const long DiaryFrame::ID_STATUSBAR1 = wxNewId();
//*)

//const long DiaryFrame::ID_Panel3 = wxNewId();

BEGIN_EVENT_TABLE(DiaryFrame,wxFrame)
	//(*EventTable(DiaryFrame)
	//*)
END_EVENT_TABLE()

DiaryFrame::DiaryFrame(wxWindow* parent,wxWindowID id) {
	//(*Initialize(DiaryFrame)
	wxMenuItem* MenuItem2;
	wxMenuBar* MenuBar;
	wxMenuItem* MenuItem1;
	wxMenu* Menu1;
	wxStaticBoxSizer* LeftPortionStaticBoxSizer;
	wxMenu* Menu2;

	Create(parent, wxID_ANY, _("Diary 15.04.0.1"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetMinSize(wxSize(150,0));
	LeftPortionStaticBoxSizer = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Diary Structure"));
	GenericDirCtrl1 = new wxGenericDirCtrl(Panel1, ID_GENERICDIRCTRL1, _T("."), wxDefaultPosition, wxSize(93,247), 0, wxEmptyString, 0, _T("ID_GENERICDIRCTRL1"));
	LeftPortionStaticBoxSizer->Add(GenericDirCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(LeftPortionStaticBoxSizer);
	LeftPortionStaticBoxSizer->Fit(Panel1);
	LeftPortionStaticBoxSizer->SetSizeHints(Panel1);
	AuiManager1->AddPane(Panel1, wxAuiPaneInfo().Name(_T("PaneName")).DefaultPane().Caption(_("Pane caption")).CaptionVisible(false).CloseButton(false).Left().MinSize(wxSize(150,0)));
	EditorsAUINBook = new wxAuiNotebook(this, ID_EditorsAUINBook, wxPoint(114,213), wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
	AuiManager1->AddPane(EditorsAUINBook, wxAuiPaneInfo().Name(_T("PaneName")).DefaultPane().Caption(_("Pane caption")).CaptionVisible(false).CloseButton(false).Row(1).Center());
	AuiManager1->Update();
	MenuBar = new wxMenuBar();
	Menu1 = new wxMenu();
	SaveMItem = new wxMenuItem(Menu1, ID_SaveMItem, _("Save\tCtrl+S"), _("Save the current file"), wxITEM_NORMAL);
	Menu1->Append(SaveMItem);
	NewFile = new wxMenuItem(Menu1, ID_NewFile, _("New File\tCtrl+N"), _("Add new tab"), wxITEM_NORMAL);
	Menu1->Append(NewFile);
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar->Append(Menu1, _("&File"));
	Menu3 = new wxMenu();
	ChangeFont = new wxMenuItem(Menu3, ID_ChangeFont, _("Change Font\tCtrl+F"), _("Select  Font"), wxITEM_NORMAL);
	Menu3->Append(ChangeFont);
	MenuBar->Append(Menu3, _("&Edit"));
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar->Append(Menu2, _("Help"));
	SetMenuBar(MenuBar);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -1 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	FileSelector = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	wxFontData fontData_1;
	fontData_1.SetInitialFont(*wxNORMAL_FONT);
	SelectFont = new wxFontDialog(this, fontData_1);
	Center();

	Connect(ID_SaveMItem,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnSaveMItemSelected);
	Connect(ID_NewFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnNewTabSelected);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnQuit);
	Connect(ID_ChangeFont,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnChangeFontSelected);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnAbout);
	//*)


	//wxCommandEvent Event; OnNewTabSelected(Event);
	//NewEditor = new TextEditor(AuiNotebook1);
	UnsavedChanges = false;
}

DiaryFrame::~DiaryFrame() {
	//(*Destroy(DiaryFrame)
	//*)
}

void DiaryFrame::OnQuit(wxCommandEvent& event) {
	if(UnsavedChanges) {
		wxString Error = wxT(" Discard file changes ??");
		wxMessageBox(Error,Error);
	} else {
		Close();
	}
}

void DiaryFrame::OnAbout(wxCommandEvent& event) {
	wxString msg = wxT(" A simple diary application concept by \n Prakash Gautam");
	wxMessageBox(msg, _("About Diary 15.04.0.1"));
}

void DiaryFrame::OnTypedRTCtrlText(wxCommandEvent& event) {
	UnsavedChanges = true;

}




void DiaryFrame::OnSaveMItemSelected(wxCommandEvent& event) {
	FileSelector->ShowModal();
	wxString Path = FileSelector->GetPath();
	//wxMessageBox(Path,wxT("Current path is "));
	if(Path == wxEmptyString) {
		//wxMessageBox(wxT("Alas this is empty"),wxT("Enter something"));
	} else {
		int SelectedPage = EditorsAUINBook->GetSelection();
		TextEditorPanel* Editor = (TextEditorPanel*)EditorsAUINBook->GetPage(SelectedPage);
		wxString Text = Editor->TypedText->GetValue();
		string Texts = string(Text.mb_str());
		string Paths = string(Path.mb_str());
		ofstream File(Paths);
		File<<Texts;
		File.close();
	}
}

void DiaryFrame::OnNewTabSelected(wxCommandEvent& event) {
	TextEditorPanel* Paage = new TextEditorPanel(EditorsAUINBook);
	EditorsAUINBook->AddPage(Paage,wxT("untitled"));
	EditorsAUINBook->SetSelection(EditorsAUINBook->GetPageCount()-1);
}

void DiaryFrame::OnChangeFontSelected(wxCommandEvent& event) {
	if(SelectFont->ShowModal()) {

	}
	wxFontData CurrentFontData = SelectFont->GetFontData();
	wxFont CurrentFont = CurrentFontData.GetChosenFont();
	SetFontOnAllPages(CurrentFont);

}

void DiaryFrame::SetFontOnAllPages(wxFont CurrentFont) {
	int NumberOfPages = EditorsAUINBook->GetPageCount();
	for(int i = 0; i< NumberOfPages; i++)
		((TextEditorPanel*)EditorsAUINBook->GetPage(i))->TypedText->SetFont(CurrentFont);
}
