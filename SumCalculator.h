//
// Created by nicco on 28/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#define SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class SumCalculator: public Observer {
public:
    SumCalculator(Spreadsheet *s, int row, int column): sum(0), spreadsheet(s), row(row), column(column){
        spreadsheet->subscribe(this);
    }

    ~SumCalculator() override {
        spreadsheet->unsubscribe(this);
    }

    void update() override;

private:
    double sum;
    Spreadsheet *spreadsheet;
    int row;
    int column;

};


#endif //SIMPLE_SPREADSHEET_SUMCALCULATOR_H
