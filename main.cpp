#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Spreadsheet.h"
#include "SumCalculator.h"
#include "MaxCalculator.h"
#include "MinCalculator.h"
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Spreadsheet *frame = new Spreadsheet(5,NULL, wxID_ANY, "Spreadsheet");
    SumCalculator *sumCalculator = new SumCalculator(frame, 0, 4);
    MaxCalculator*  max = new MaxCalculator(1, 4 ,frame);
    MinCalculator* min = new MinCalculator(2, 4, frame);
    frame->Show( true );
    return true;
}
