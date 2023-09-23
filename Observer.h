//
// Created by nicco on 28/08/23.
//

#ifndef SIMPLE_SPREADSHEET_OBSERVER_H
#define SIMPLE_SPREADSHEET_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;
};

#endif //SIMPLE_SPREADSHEET_OBSERVER_H
