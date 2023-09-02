//
// Created by nicco on 01/09/23.
//

#ifndef SIMPLE_SPREADSHEET_CELL_H
#define SIMPLE_SPREADSHEET_CELL_H
#include "Observer.h"
#include "Subject.h"
#include <wx/wx.h>
#include <list>
#include <string>

class Cell: public Observer, public Subject{
public:
    Cell(int row, int column, wxTextCtrl* Textctrl): row(row), column(column), value(0), formula("none"), textCtrl(Textctrl){
        textCtrl->Bind(wxEVT_TEXT, &Cell::notify, this);
    }
    ~Cell() override{
        observers.clear();
        subjects.clear();
        textCtrl->Unbind(wxEVT_TEXT, &Cell::notify, this);
    }

    void subscribe(Observer* obs) override{
        observers.push_back(obs);
    }

    void unsubscribe(Observer* obs) override{
        observers.remove(obs);
    }

    void notify(wxCommandEvent &event) override{
        for(auto obs: observers){
            obs->update();
        }
    }

    double getValue() const {
        return value;
    }

    void setValue() {
        if(isLegalCharacter()) {
            value = std::stod(textCtrl->GetValue().ToStdString());
        }
    }

private:
    int row, column;
    double value;
    std::string formula;
    wxTextCtrl* textCtrl;
    std::list<Observer*> observers;
    std::list<Cell*> subjects;
    bool isLegalCharacter() const;


};


#endif //SIMPLE_SPREADSHEET_CELL_H
