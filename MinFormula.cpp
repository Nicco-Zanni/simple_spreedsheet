//
// Created by nicco on 23/09/23.
//

#include "MinFormula.h"

double MinFormula::compute(const std::vector<double> &values) {
    double min = values[0];
    for(auto value : values) {
        if(value < min) {
            min = value;
        }
    }
    return min;
}