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
        if(row >= 0 && row < spreadsheet->getRows() && column >=0 && column < spreadsheet->getColumns()){
            if(!spreadsheet->isObserverCell(row, column)) {
                spreadsheet->subscribe(this);
                spreadsheet->setObserverCell(row, column);
            } else{
                std::cout << "Cell already occupied by another observer" << std::endl;
            }
        } else{
            std::cout << "Out of limits" << std::endl;
        }
    }
    ~MaxCalculator() override{
        spreadsheet->unsubscribe(this);
    }

    void update() override;
private:
    int row;
    int column;
    double max;
    Spreadsheet* spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_MAXCALCULATOR_H
