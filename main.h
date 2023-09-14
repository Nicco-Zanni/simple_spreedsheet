//
// Created by nicco on 14/09/23.
//

#ifndef SIMPLE_SPREADSHEET_MAIN_H
#define SIMPLE_SPREADSHEET_MAIN_H
#include <wx/wx.h>
#include "Spreadsheet.h"
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
private:
    Spreadsheet* frame;
};

#endif //SIMPLE_SPREADSHEET_MAIN_H
