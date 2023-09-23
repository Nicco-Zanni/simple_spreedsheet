//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_FORMULA_H
#define SIMPLE_SPREADSHEET_FORMULA_H
#include <vector>
class Formula {
public:
    virtual ~Formula() {};

    virtual double compute(const std::vector<double> &values) = 0;
};

#endif //SIMPLE_SPREADSHEET_FORMULA_H
