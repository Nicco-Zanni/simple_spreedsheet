//
// Created by nicco on 29/08/23.
//

#ifndef SIMPLE_SPREADSHEET_MINCALCULATOR_H
#define SIMPLE_SPREADSHEET_MINCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class MinCalculator: public Observer{
public:
    MinCalculator(int row, int column, Spreadsheet* s): row(row), column(column), min(0), spreadsheet(s){
        spreadsheet->subscribe(this);
    }

    ~MinCalculator() override{
        spreadsheet->unsubscribe(this);
    }

    void update() override;
private:
    int row;
    int column;
    double min;
    Spreadsheet* spreadsheet;
};


#endif //SIMPLE_SPREADSHEET_MINCALCULATOR_H
