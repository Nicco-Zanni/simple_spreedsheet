//
// Created by nicco on 23/09/23.
//

#include "MeanFormula.h"

double MeanFormula::compute(const std::vector<double> &values) {
    double mean = 0;
    for(auto value : values) {
        mean += value;
    }
    return mean / values.size();
}