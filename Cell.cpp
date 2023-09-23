//
// Created by nicco on 01/09/23.
//

#include "Cell.h"

bool Cell::isLegalCharacter() const {
    if(textCtrl->GetValue() != wxT("-") && textCtrl->GetValue() != wxT("+")){
        return true;
    }
    return false;
}

void Cell::setFormula(const std::string &formula) {
    Cell::formula = formula;
}

bool Cell::isEmpty() const {
    if(textCtrl->GetValue() == wxEmptyString){
        return true;
    }
    return false;
}

void Cell::update() {
    compute();
    setResult();

}

void Cell::compute(const std::vector<double> &values) {

}


void Cell::setResult() {
    textCtrl->SetValue(wxString::Format(wxT("%f"), value));
}

void Cell::removeSubjects() {
    for(auto subject : subjects){
        subject->unsubscribe(this);
    }
    subjects.clear();
}

void Cell::addSubject(Cell *subject) {
    subjects.push_back(subject);
}

const std::string &Cell::getFormula() const {
    return formula;
}

const std::list<Observer *> &Cell::getObservers() const {
    return observers;
}

const std::list<Cell *> &Cell::getSubjects() const {
    return subjects;
}

wxTextCtrl *Cell::getTextCtrl() const {
    return textCtrl;
}
