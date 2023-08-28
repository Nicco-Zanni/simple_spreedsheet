//
// Created by nicco on 25/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SPREADSHEET_H
#define SIMPLE_SPREADSHEET_SPREADSHEET_H

#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <vector>

class Spreadsheet: public wxFrame {
public:
    explicit Spreadsheet(int numOfColumns, wxWindow *parent = nullptr, wxWindowID id = wxID_ANY,
                         const wxString &title = wxEmptyString, const wxPoint &pos = wxDefaultPosition,
                         const wxSize &size = wxDefaultSize,
                         long style = wxDEFAULT_FRAME_STYLE, const wxString &name = wxFrameNameStr);
private:
    int columns;
    const int rows = 4;
    std::vector<wxTextCtrl *> cells;
    wxGridSizer *gridSizerCells;
    void setupGrid();
};


#endif //SIMPLE_SPREADSHEET_SPREADSHEET_H
