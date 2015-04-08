/***************************************************************
 * Name:      DiaryApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-04-08
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "DiaryApp.h"

//(*AppHeaders
#include "DiaryMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DiaryApp);

bool DiaryApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	DiaryFrame* Frame = new DiaryFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
