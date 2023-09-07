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
    explicit Cell(wxTextCtrl* Textctrl): value(0), formula("none"), textCtrl(Textctrl){
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
        setValue();
        for(auto obs: observers){
            obs->update();
        }
    }

    double getValue() const {
        return value;
    }

    void setValue() {
        if(!isEmpty() && isLegalCharacter()) {
            value = std::stod(textCtrl->GetValue().ToStdString());
        }
    }

    void setFormula(const std::string &formula);

    void update() override;

    void setResult();

    void removeSubjects();

    void addSubject(Cell* subject);

    const std::string &getFormula() const;

    const std::list<Observer *> &getObservers() const;

    const std::list<Cell *> &getSubjects() const;
    bool isLegalCharacter() const;
    bool isEmpty() const;

    wxTextCtrl *getTextCtrl() const;

private:
    double value;
    std::string formula;
    wxTextCtrl* textCtrl;
    std::list<Observer*> observers;
    std::list<Cell*> subjects;
    void compute();
    void computeSum();
    void computeMax();
    void computeMin();
    void computeMean();

};


#endif //SIMPLE_SPREADSHEET_CELL_H
