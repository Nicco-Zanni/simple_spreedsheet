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
