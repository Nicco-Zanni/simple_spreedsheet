//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_MAXFORMULA_H
#define SIMPLE_SPREADSHEET_MAXFORMULA_H
#include "Formula.h"

class MaxFormula: public Formula{
public:
    double compute(const std::vector<double> &values) override;
};


#endif //SIMPLE_SPREADSHEET_MAXFORMULA_H
