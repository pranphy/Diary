#include "TextEditorPanel.h"

//(*InternalHeaders(TextEditorPanel)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//(*IdInit(TextEditorPanel)
const long TextEditorPanel::ID_TypedText = wxNewId();
const long TextEditorPanel::ID_BUTTON1 = wxNewId();
const long TextEditorPanel::ID_EncryptButton = wxNewId();
//*)

BEGIN_EVENT_TABLE(TextEditorPanel,wxPanel)
	//(*EventTable(TextEditorPanel)
	//*)
END_EVENT_TABLE()

TextEditorPanel::TextEditorPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) {
	//(*Initialize(TextEditorPanel)
	wxGridBagSizer* GridBagSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	GridBagSizer1->AddGrowableCol(0);
	GridBagSizer1->AddGrowableRow(0);
	TypedText = new wxRichTextCtrl(this, ID_TypedText, wxEmptyString, wxDefaultPosition, wxSize(258,226), wxRE_MULTILINE, wxDefaultValidator, _T("ID_TypedText"));
	wxRichTextAttr rchtxtAttr_1;
	rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
	wxFont Font_1(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monaco"),wxFONTENCODING_DEFAULT);
	rchtxtAttr_1.SetFontFaceName(Font_1.GetFaceName());
	rchtxtAttr_1.SetFontSize(Font_1.GetPointSize());
	rchtxtAttr_1.SetFontStyle(Font_1.GetStyle());
	rchtxtAttr_1.SetFontUnderlined(Font_1.GetUnderlined());
	rchtxtAttr_1.SetFontWeight(Font_1.GetWeight());
	TypedText->SetBasicStyle(rchtxtAttr_1);
	GridBagSizer1->Add(TypedText, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Actions"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	EncryptButton = new wxButton(this, ID_EncryptButton, _("Encrypt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EncryptButton"));
	StaticBoxSizer1->Add(EncryptButton, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	GridBagSizer1->Add(StaticBoxSizer1, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);

	Connect(ID_EncryptButton,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextEditorPanel::OnEncryptButtonClick);
	//*)
}
//BMP files (*.bmp)|*.bmp|GIF files (*.gif)|*.gif


TextEditorPanel::~TextEditorPanel() {
	//(*Destroy(TextEditorPanel)
	//*)
}


void TextEditorPanel::OnEncryptButtonClick(wxCommandEvent& event) {
	wxString Text = TypedText->GetValue();
	string Typed = string(Text.mb_str());

	//wxMessageBox(Text,wxT("The typed text"));
	XOREncrypt EN(Typed,"$%^");
	EN.Encrypt();
	string Encrypted = EN.GetEncrypted();
	ofstream File("TestFile.txt");
	File<<Encrypted<<endl;
	wxString Fest;
	unsigned Size = Encrypted.size();
	unsigned i = 0;
	for(;i<Size;i++){
		Fest += Encrypted.at(i);
	}

	wxString New = wxString::From8BitData(EN.GetCharArray());
	//wxMessageBox(New,wxT(" Encrypted text"));
	TypedText->SetValue(Fest);
}
