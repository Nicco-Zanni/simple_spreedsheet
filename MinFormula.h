//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_MINFORMULA_H
#define SIMPLE_SPREADSHEET_MINFORMULA_H
#include "Formula.h"

class MinFormula: public Formula{
public:
    double compute(const std::vector<double> &values) override;

};


#endif //SIMPLE_SPREADSHEET_MINFORMULA_H
