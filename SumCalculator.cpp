//
// Created by nicco on 28/08/23.
//

#include "SumCalculator.h"

void SumCalculator::update() {
    sum = 0;
    for(int i = 0; i < column; i++){
            sum += spreadsheet->getCellValueAt(row, i);
    }
    spreadsheet->setResult(sum, row, column);

}