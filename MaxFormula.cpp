//
// Created by nicco on 23/09/23.
//

#include "MaxFormula.h"

double MaxFormula::compute(const std::vector<double> &values) {
    double max = values[0];
    for (auto value: values) {
        if (value > max) {
            max = value;
        }
    }
    return max;
}