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
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/treectrl.h>
//*)

class DiaryFrame: public wxFrame
{
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
        //*)

        //(*Identifiers(DiaryFrame)
        static const long ID_TREECTRL1;
        static const long ID_TypedRTCtrl;
        static const long ID_PANEL1;
        static const long ID_NOTEBOOK1;
        static const long ID_SaveButton;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(DiaryFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* SaveButton;
        wxTreeCtrl* TreeCtrl1;
        wxNotebook* Notebook1;
        wxRichTextCtrl* TypedRTCtrl;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DIARYMAIN_H
