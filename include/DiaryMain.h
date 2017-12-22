/***************************************************************
 * Name:      DiaryMain.h
 * Purpose:   Defines Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-04-08
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#ifndef DIARYMAIN_H
#define DIARYMAIN_H

//(*Headers(DiaryFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/dirctrl.h>
#include <wx/aui/aui.h>
#include <wx/fontdlg.h>
//*)
#include<vector>

#include "TextEditorPanel.h"

using namespace std;

class DiaryFrame: public wxFrame {
public:

	DiaryFrame(wxWindow* parent,wxWindowID id = -1);
	virtual ~DiaryFrame();

	bool UnsavedChanges;

private:

	//(*Handlers(DiaryFrame)
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnTypedRTCtrlText(wxCommandEvent& event);
	void OnTypedRTCtrlText1(wxCommandEvent& event);
	void OnTypedRTCtrlText2(wxCommandEvent& event);
	void OnTypedRTCtrlText3(wxCommandEvent& event);
	void OnSaveButtonClick(wxCommandEvent& event);
	void OnSaveMItemSelected(wxCommandEvent& event);
	void OnNewTabSelected(wxCommandEvent& event);
	void OnChangeFontSelected(wxCommandEvent& event);
	//*)

	//(*Identifiers(DiaryFrame)
	static const long ID_GENERICDIRCTRL1;
	static const long ID_PANEL1;
	static const long ID_EditorsAUINBook;
	static const long ID_SaveMItem;
	static const long ID_NewFile;
	static const long ID_MENUITEM1;
	static const long ID_ChangeFont;
	static const long idMenuAbout;
	static const long ID_STATUSBAR1;
	//*)

	//(*Declarations(DiaryFrame)
	wxAuiNotebook* EditorsAUINBook;
	wxMenuItem* ChangeFont;
	wxPanel* Panel1;
	wxStatusBar* StatusBar1;
	wxMenu* Menu3;
	wxGenericDirCtrl* GenericDirCtrl1;
	wxMenuItem* SaveMItem;
	wxFontDialog* SelectFont;
	wxMenuItem* NewFile;
	wxAuiManager* AuiManager1;
	wxFileDialog* FileSelector;
	//*)
	//vector<TextEditor*> Editors;
	//TextEditor* NewEditor;

	void SetFontOnAllPages(wxFont);

	TextEditorPanel* TextEditor;
	DECLARE_EVENT_TABLE()
};

#endif // DIARYMAIN_H
