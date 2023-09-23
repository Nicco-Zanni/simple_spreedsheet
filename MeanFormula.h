//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_MEANFORMULA_H
#define SIMPLE_SPREADSHEET_MEANFORMULA_H

#include "Formula.h"

class MeanFormula : public Formula {
public:
    double compute(const std::vector<double> &values) override;
};

#endif //SIMPLE_SPREADSHEET_MEANFORMULA_H
