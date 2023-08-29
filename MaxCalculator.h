//
// Created by nicco on 29/08/23.
//

#ifndef SIMPLE_SPREADSHEET_MAXCALCULATOR_H
#define SIMPLE_SPREADSHEET_MAXCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class MaxCalculator: public Observer{
public:
    MaxCalculator(int row, int column, Spreadsheet* s): row(row), column(column), max(0), spreadsheet(s){
        spreadsheet->subscribe(this);
    }
    ~MaxCalculator(){
        spreadsheet->unsubscribe(this);
    }
private:
    int row;
    int column;
    double max;
    Spreadsheet* spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_MAXCALCULATOR_H
