#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Spreadsheet.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Spreadsheet *frame = new Spreadsheet(5, 5,NULL, wxID_ANY, "Spreadsheet");
    frame->Show( true );
    return true;
}
