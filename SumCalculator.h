//
// Created by nicco on 28/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#define SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class SumCalculator: public Observer {
public:
    SumCalculator(int row, int column, Spreadsheet *s): sum(0), row(row), column(column), spreadsheet(s){
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

    ~SumCalculator() override {
        spreadsheet->unsubscribe(this);
    }

    void update() override;
private:
    int row;
    int column;
    double sum;
    Spreadsheet *spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_SUMCALCULATOR_H
