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
