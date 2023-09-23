//
// Created by nicco on 23/09/23.
//

#include "SumFormula.h"

double SumFormula::compute(const std::vector<double> &values) {
    double sum = 0;
    for(auto value : values) {
        sum += value;
    }
    return sum;
}