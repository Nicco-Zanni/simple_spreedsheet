//
// Created by nicco on 23/09/23.
//

#ifndef SIMPLE_SPREADSHEET_FORMULA_H
#define SIMPLE_SPREADSHEET_FORMULA_H

class Formula {
    public:
    virtual ~Formula() = default;

    virtual void compute() = 0;
};

#endif //SIMPLE_SPREADSHEET_FORMULA_H
