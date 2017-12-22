#ifndef TEXTEDITORPANEL_H
#define TEXTEDITORPANEL_H


#include "XOREncrypt.h"

#include <wx/msgdlg.h>
#include <fstream>
using namespace std;
//(*Headers(TextEditorPanel)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/gbsizer.h>
//*)

class TextEditorPanel: public wxPanel {
public:

	TextEditorPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
	virtual ~TextEditorPanel();
	//wxPanel* GetPanel();

	//(*Declarations(TextEditorPanel)
	wxButton* Button1;
	wxButton* EncryptButton;
	wxRichTextCtrl* TypedText;
	//*)

protected:

	//(*Identifiers(TextEditorPanel)
	static const long ID_TypedText;
	static const long ID_BUTTON1;
	static const long ID_EncryptButton;
	//*)

private:

	//(*Handlers(TextEditorPanel)
	void OnEncryptButtonClick(wxCommandEvent& event);
	//*)

	DECLARE_EVENT_TABLE()
};

#endif
