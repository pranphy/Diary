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

using namespace std;

//(*InternalHeaders(DiaryFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(DiaryFrame)
const long DiaryFrame::ID_TREECTRL1 = wxNewId();
const long DiaryFrame::ID_TypedRTCtrl = wxNewId();
const long DiaryFrame::ID_PANEL1 = wxNewId();
const long DiaryFrame::ID_NOTEBOOK1 = wxNewId();
const long DiaryFrame::ID_DiaryFPCtrl = wxNewId();
const long DiaryFrame::ID_SaveButton = wxNewId();
const long DiaryFrame::idMenuQuit = wxNewId();
const long DiaryFrame::idMenuAbout = wxNewId();
const long DiaryFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DiaryFrame,wxFrame)
    //(*EventTable(DiaryFrame)
    //*)
END_EVENT_TABLE()

DiaryFrame::DiaryFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DiaryFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxGridBagSizer* GridBagSizer1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
    TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(173,517), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    StaticBoxSizer1->Add(TreeCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(StaticBoxSizer1, wxGBPosition(0, 0), wxGBSpan(2, 1), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(736,462), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxSize(738,319), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    TypedRTCtrl = new wxRichTextCtrl(Panel1, ID_TypedRTCtrl, wxEmptyString, wxPoint(0,0), wxSize(730,433), wxRE_MULTILINE, wxDefaultValidator, _T("ID_TypedRTCtrl"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    wxFont Font_1(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monaco"),wxFONTENCODING_DEFAULT);
    rchtxtAttr_1.SetFontFaceName(Font_1.GetFaceName());
    rchtxtAttr_1.SetFontSize(Font_1.GetPointSize());
    rchtxtAttr_1.SetFontStyle(Font_1.GetStyle());
    rchtxtAttr_1.SetFontUnderlined(Font_1.GetUnderlined());
    rchtxtAttr_1.SetFontWeight(Font_1.GetWeight());
    TypedRTCtrl->SetBasicStyle(rchtxtAttr_1);
    Notebook1->AddPage(Panel1, _("DiaryOne"), false);
    StaticBoxSizer2->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(StaticBoxSizer2, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->Add(546,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DiaryFPCtrl = new wxFontPickerCtrl(this, ID_DiaryFPCtrl, wxNullFont, wxDefaultPosition, wxSize(110,27), wxFNTP_FONTDESC_AS_LABEL|wxFNTP_USEFONT_FOR_LABEL, wxDefaultValidator, _T("ID_DiaryFPCtrl"));
    FlexGridSizer1->Add(DiaryFPCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SaveButton = new wxButton(this, ID_SaveButton, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SaveButton"));
    FlexGridSizer1->Add(SaveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(FlexGridSizer1, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridBagSizer1->Fit(this);
    GridBagSizer1->SetSizeHints(this);

    Connect(ID_TypedRTCtrl,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DiaryFrame::OnTypedRTCtrlText);
    Connect(ID_DiaryFPCtrl,wxEVT_COMMAND_FONTPICKER_CHANGED,(wxObjectEventFunction)&DiaryFrame::OnDiaryFPCtrlFontChanged);
    Connect(ID_SaveButton,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DiaryFrame::OnSaveButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&DiaryFrame::OnAbout);
    //*)
    UnsavedChanges = false;
}

DiaryFrame::~DiaryFrame()
{
    //(*Destroy(DiaryFrame)
    //*)
}

void DiaryFrame::OnQuit(wxCommandEvent& event)
{
    if(UnsavedChanges){
        wxString Error = wxT(" Discard file changes ");
        wxMessageBox(Error,Error);
    } else {
        Close();
    }
}

void DiaryFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DiaryFrame::OnTypedRTCtrlText(wxCommandEvent& event)
{
    UnsavedChanges = true;

}




void DiaryFrame::OnSaveButtonClick(wxCommandEvent& event)
{
    string Filename  = "TestFileName.txt";
    ofstream File(Filename);
    wxString  Text = TypedRTCtrl->GetValue();
    string Typed = string(Text.mb_str());
    File<<Typed;
    File.close();
    UnsavedChanges = false;
}

void DiaryFrame::OnDiaryFPCtrlFontChanged(wxFontPickerEvent& event)
{
    wxFont CurrentFont = DiaryFPCtrl->GetSelectedFont();
    TypedRTCtrl->SetFont(CurrentFont);
}
