//
// Created by nicco on 28/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SUBJECT_H
#define SIMPLE_SPREADSHEET_SUBJECT_H
#include "Observer.h"
#include <wx/wx.h>

class Subject {
public:
    virtual ~Subject() {}

    virtual void subscribe(Observer *obs) = 0;

    virtual void unsubscribe(Observer *obs) = 0;

    virtual void notify(wxCommandEvent & event) = 0;

};


#endif //SIMPLE_SPREADSHEET_SUBJECT_H
