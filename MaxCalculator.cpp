//
// Created by nicco on 29/08/23.
//

#include "MaxCalculator.h"

void MaxCalculator::update() {
    int i = 0;
    while(spreadsheet->isEmpty(row, i)) {
        i++;
    }
    max = spreadsheet->getCellValueAt(row, i);
    for(int j = 1; j < column; j++){
        if(max < spreadsheet->getCellValueAt(row, j) && !spreadsheet->isEmpty(row, j)){
            max = spreadsheet->getCellValueAt(row, j);
        }
    }
    spreadsheet->setResult(max, row, column);
}