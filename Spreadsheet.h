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



    ~Spreadsheet() override;

    void subscribe(Observer *obs) override{
        observers.push_back(obs);
    }

    void unsubscribe(Observer *obs) override{
        observers.remove(obs);
    }

    void notify(wxCommandEvent & event ) override;

    double getCellValueAt(int x, int y) const;

    void setResult(double result, int x, int y);

    bool isEmpty(int x, int y) const;

    int getColumns() const;

    const int getRows() const;

    bool isObserverCell(int x, int y) const;

    void setObserverCell(int x, int y);

private:
    int columns;
    const int rows = 4;
    std::vector<wxTextCtrl *> cells;
    std::list<Observer *> observers;
    std::vector<bool> observerCell;
    void setupGrid();
    bool isLegalCharacter(int x, int y) const;
};


#endif //SIMPLE_SPREADSHEET_SPREADSHEET_H
