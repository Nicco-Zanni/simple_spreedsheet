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
    ~MeanCalculator(){
        spreadsheet->unsubscribe(this);
    }

    void update() override;

private:
    int row, column;
    double mean;
    Spreadsheet* spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_MEANCALCULATOR_H
