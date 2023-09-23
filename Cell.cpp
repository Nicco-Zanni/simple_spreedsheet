//
// Created by nicco on 01/09/23.
//

#include "Cell.h"
#include "MaxFormula.h"
#include "SumFormula.h"
#include "MinFormula.h"
#include "MeanFormula.h"

bool Cell::isLegalCharacter() const {
    if(textCtrl->GetValue() != wxT("-") && textCtrl->GetValue() != wxT("+")){
        return true;
    }
    return false;
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

void Cell::compute() {
    std::vector<double> values;
    for(auto subject : subjects){
        values.push_back(subject->getValue());
    }
    value = formula->compute(values);
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

const std::list<Observer *> &Cell::getObservers() const {
    return observers;
}

const std::list<Cell *> &Cell::getSubjects() const {
    return subjects;
}

wxTextCtrl *Cell::getTextCtrl() const {
    return textCtrl;
}

Formula *Cell::getFormula() const {
    return formula;
}

void Cell::setFormula(FormulaType type) {
    switch (type) {
        case FormulaType::sum:
            formula = new SumFormula();
            break;
        case FormulaType::max:
            formula = new MaxFormula();
            break;
        case FormulaType::min:
            formula = new MinFormula();
            break;
        case FormulaType::mean:
            formula = new MeanFormula();
            break;
        case FormulaType::none:
            formula = nullptr;
            break;
        default:
            formula = nullptr;
            break;
    }
}
