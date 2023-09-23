//
// Created by nicco on 23/09/23.
//
#include "../SumFormula.h"
#include "../MaxFormula.h"
#include "../MinFormula.h"
#include "../MeanFormula.h"
#include <gtest/gtest.h>

TEST(FormulaSuite, SumFormulaComputeTest){
    SumFormula formula;
    std::vector<double> values = {1.333, 2.457, -3.9863, 4.456, 5.1};
    EXPECT_EQ(formula.compute(values), 9.3597);
    values = {-1.333, -2.457, -3.9863, -4.456, -5.1, 0};
    EXPECT_EQ(formula.compute(values), -17.3323);
}

TEST(FormulaSuite, MaxFormulaComputeTest){
    MaxFormula formula;
    std::vector<double> values = {1.333, 2.457, -3.9863, 4.456, 5.1, 0};
    EXPECT_EQ(formula.compute(values), 5.1);
    values = {-1.333, -2.457, -3.9863, -4.456, -5.1, -1.334};
    EXPECT_EQ(formula.compute(values), -1.333);
}

TEST(FormulaSuite, MinFormulaComputeTest){
    MinFormula formula;
    std::vector<double> values = {1.333, 2.457, -3.9863, 4.456, 5.1, 0};
    EXPECT_EQ(formula.compute(values), -3.9863);
    values = {-1.333, -2.457, -3.9863, -4.456, -5.1896, -1.334, -5.1895};
    EXPECT_EQ(formula.compute(values), -5.1896);
}