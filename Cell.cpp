//
// Created by nicco on 01/09/23.
//

#include "Cell.h"

bool Cell::isLegalCharacter() const {
    if (textCtrl->GetValue() != wxT("-") && textCtrl->GetValue() != wxT("+")) {
        return true;
    }
    return false;
}

bool Cell::isEmpty() const {
    if (textCtrl->GetValue() == wxEmptyString) {
        return true;
    }
    return false;
}

void Cell::update() {
    compute();
    setResult();

}

void Cell::compute() {
    if (formula != nullptr) {
        std::vector<double> values;
        for (auto subject: subjects) {
            if (!subject->isEmpty() && subject->isLegalCharacter())
                values.push_back(subject->getValue());
        }
        if (!values.empty())
            value = formula->compute(values);
        else
            value = 0;
    }
}


void Cell::setResult() {
    textCtrl->SetValue(wxString::Format(wxT("%f"), value));
}

void Cell::removeSubjects() {
    for (auto subject: subjects) {
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
    delete formula;
    switch (type) {
        case FormulaType::sum:
            formula = new SumFormula;
            break;
        case FormulaType::max:
            formula = new MaxFormula;
            break;
        case FormulaType::min:
            formula = new MinFormula;
            break;
        case FormulaType::mean:
            formula = new MeanFormula;
            break;
        case FormulaType::none:
            formula = nullptr;
            break;
        default:
            formula = nullptr;
            break;
    }
}
