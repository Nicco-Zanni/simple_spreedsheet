//
// Created by nicco on 29/08/23.
//

#include "MeanCalculator.h"

void MeanCalculator::update(){
    mean = 0;
    int count = 0;
    for(int i = 0; i < column; i++){
        if(!spreadsheet->isEmpty(row, i)){
            mean += spreadsheet->getCellValueAt(row, i);
            count ++;
        }
    }
    if(count > 0)
        mean = mean / count;
    spreadsheet->setResult(mean, row, column);
}