//
// Created by nicco on 29/08/23.
//

#include "MaxCalculator.h"

void MaxCalculator::update() {
    max = spreadsheet->getCellValueAt(row, 0);
    for(int i = 1; i < column; i++){
        if(max < spreadsheet->getCellValueAt(row, i)){
            max = spreadsheet->getCellValueAt(row, i);
        }
    }
    spreadsheet->setResult(max, row, column);
}