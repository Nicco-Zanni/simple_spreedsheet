//
// Created by nicco on 01/09/23.
//

#ifndef SIMPLE_SPREADSHEET_CELL_H
#define SIMPLE_SPREADSHEET_CELL_H

#include "Observer.h"
#include "Subject.h"
#include "Formula.h"
#include "MaxFormula.h"
#include "SumFormula.h"
#include "MinFormula.h"
#include "MeanFormula.h"
#include <wx/wx.h>
#include <list>
#include <string>
#include <vector>

enum FormulaType {
    sum, max, min, mean, none
};

class Cell : public Observer, public Subject {
public:
    explicit Cell(wxTextCtrl *Textctrl) : value(0), formula(nullptr), textCtrl(Textctrl) {
        textCtrl->Bind(wxEVT_TEXT, &Cell::notify, this);
    }

    ~Cell() override {
        observers.clear();
        subjects.clear();
        delete formula;
        textCtrl->Unbind(wxEVT_TEXT, &Cell::notify, this);
    }

    void subscribe(Observer *obs) override {
        observers.push_back(obs);
    }

    void unsubscribe(Observer *obs) override {
        observers.remove(obs);
    }

    void notify(wxCommandEvent &event) override {
        setValue();
        for (auto obs: observers) {
            obs->update();
        }
    }

    double getValue() const {
        return value;
    }

    void setValue() {
        if (!isEmpty() && isLegalCharacter()) {
            value = std::stod(textCtrl->GetValue().ToStdString());
        }
    }

    void changeValue(double v) {
        value = v;
    }

    void update() override;

    void setResult();

    void removeSubjects();

    void addSubject(Cell *subject);

    const std::list<Observer *> &getObservers() const;

    const std::list<Cell *> &getSubjects() const;

    bool isLegalCharacter() const;

    bool isEmpty() const;

    wxTextCtrl *getTextCtrl() const;

    Formula *getFormula() const;

    void setFormula(FormulaType type);

private:
    double value;
    Formula *formula;
    wxTextCtrl *textCtrl;
    std::list<Observer *> observers;
    std::list<Cell *> subjects;

    void compute();
};

#endif //SIMPLE_SPREADSHEET_CELL_H
