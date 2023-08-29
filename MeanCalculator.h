//
// Created by nicco on 29/08/23.
//

#ifndef SIMPLE_SPREADSHEET_MEANCALCULATOR_H
#define SIMPLE_SPREADSHEET_MEANCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class MeanCalculator: public Observer{
public:
    MeanCalculator(int row, int column, Spreadsheet* s): row(row), column(column), mean(0), spreadsheet(s){
        spreadsheet->subscribe(this);
    }
    ~MeanCalculator(){
        spreadsheet->unsubscribe(this);
    }

private:
    int row, column;
    double mean;
    Spreadsheet* spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_MEANCALCULATOR_H
