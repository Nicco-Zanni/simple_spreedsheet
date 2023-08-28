//
// Created by nicco on 28/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#define SIMPLE_SPREADSHEET_SUMCALCULATOR_H
#include "Observer.h"
#include "Spreadsheet.h"

class SumCalculator: public Observer {
public:
    explicit SumCalculator(Spreadsheet *s): sum(0), spreadsheet(s) {
        spreadsheet->subscribe(this);
    }

    void update() override;

private:
    double sum;
    Spreadsheet *spreadsheet;

};


#endif //SIMPLE_SPREADSHEET_SUMCALCULATOR_H
