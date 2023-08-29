//
// Created by nicco on 29/08/23.
//

#include "MinCalculator.h"

void MinCalculator::update() {
    min = 0;
    int i = 0;
    while(i < column && spreadsheet->isEmpty(row, i)) {
        i++;
    }
    if( i < column)
        min = spreadsheet->getCellValueAt(row, i);
    for(int j = i; j < column; j++){
        if(min > spreadsheet->getCellValueAt(row, j) && !spreadsheet->isEmpty(row, j)){
            min = spreadsheet->getCellValueAt(row, j);
        }
    }
    spreadsheet->setResult(min, row, column);
}