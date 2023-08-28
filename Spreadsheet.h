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
#include <list>
#include "Observer.h"
#include "Subject.h"

class Spreadsheet: public wxFrame, public Subject{
public:
    explicit Spreadsheet(int numOfColumns, wxWindow *parent = nullptr, wxWindowID id = wxID_ANY,
                         const wxString &title = wxEmptyString, const wxPoint &pos = wxDefaultPosition,
                         const wxSize &size = wxDefaultSize,
                         long style = wxDEFAULT_FRAME_STYLE, const wxString &name = wxFrameNameStr);

    void subscribe(Observer *obs) override{
        observers.push_back(obs);
    }

    void unsubscribe(Observer *obs) override{
        observers.remove(obs);
    }

    ~Spreadsheet() override;
private:
    int columns;
    const int rows = 4;
    std::vector<wxTextCtrl *> cells;
    wxGridSizer *gridSizerCells;
    std::list<Observer *> observers;
    void setupGrid();
};


#endif //SIMPLE_SPREADSHEET_SPREADSHEET_H
