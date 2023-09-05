//
// Created by nicco on 01/09/23.
//

#include "Cell.h"

bool Cell::isLegalCharacter() const {
    if(textCtrl->GetValue() != wxT("-") && textCtrl->GetValue() != wxT("+")){
        return false;
    }
    return true;
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

void Cell::compute() {
    if(formula == "sum"){
        computeSum();
    }else if(formula == "max"){
        computeMax();
    }else if(formula == "min"){
        computeMin();
    }else if(formula == "mean"){
        computeMean();
    }
}

void Cell::computeSum() {
    double sum = 0;
    for(auto cell : subjects){
        if(!cell->isEmpty()){
            sum += cell->getValue();
        }
    }
    value = sum;
}

void Cell::computeMax() {
    auto ptr = subjects.begin();
    while(ptr != subjects.end() && (*ptr)->isEmpty()){
        ptr++;
    }
    if(ptr != subjects.end()){
        double max = (*ptr)->getValue();
        ptr++;
        while(ptr != subjects.end()){
            if(!(*ptr)->isEmpty()){
                if(max < (*ptr)->getValue()){
                    max = (*ptr)->getValue();
                }
            }
            ptr++;
        }
        value = max;
    } else{
        value = 0;
    }
}

void Cell::computeMin(){
    auto ptr = subjects.begin();
    while(ptr != subjects.end() && (*ptr)->isEmpty()){
        ptr++;
    }
    if(ptr != subjects.end()){
        double min = (*ptr)->getValue();
        ptr++;
        while(ptr != subjects.end()){
            if(!(*ptr)->isEmpty()){
                if(min > (*ptr)->getValue()){
                    min = (*ptr)->getValue();
                }
            }
            ptr++;
        }
        value = min;
    } else{
        value = 0;
    }
}

void Cell::computeMean() {
    auto ptr = subjects.begin();
    while(ptr != subjects.end() && (*ptr)->isEmpty()){
        ptr++;
    }
    if(ptr != subjects.end()){
        double mean = (*ptr)->getValue();
        int count = 1;
        ptr++;
        while(ptr != subjects.end()){
            if(!(*ptr)->isEmpty()){
                mean += (*ptr)->getValue();
                count++;
            }
            ptr++;
        }
        value = mean / count;
    } else{
        value = 0;
    }
}

void Cell::setResult() {
    textCtrl->ChangeValue(wxString::Format(wxT("%f"), value));
}

const std::string &Cell::getFormula() const {
    return formula;
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

void Cell::triggerNotify() {
    textCtrl->SetValue(wxString::Format(wxT("%f"), value));
}
