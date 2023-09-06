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
    frame->setObserverHorizontal(0,4, "sum");
    frame->setObserverHorizontal(1,4, "max");
    frame->setObserverHorizontal(2,4, "min");
    frame->setObserverHorizontal(3,4, "mean");
    frame->setObserverVertical(1, 3, "sum");
    frame->Show( true );
    return true;
}
