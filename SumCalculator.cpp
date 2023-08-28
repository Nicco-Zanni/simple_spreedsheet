//
// Created by nicco on 28/08/23.
//

#include "SumCalculator.h"

void SumCalculator::update() {
    sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            sum += spreadsheet->getCellValueAt(i, j);
        }
    }
    spreadsheet->setResult(sum, row, column);
}