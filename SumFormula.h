//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_SUMFORMULA_H
#define SIMPLE_SPREADSHEET_SUMFORMULA_H

#include "Formula.h"
class SumFormula: public Formula{
public:
    double compute(const std::vector<double> &values) override;
};


#endif //SIMPLE_SPREADSHEET_SUMFORMULA_H
