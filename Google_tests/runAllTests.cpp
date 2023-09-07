//
// Created by nicco on 06/09/23.
//
#include <gtest/gtest.h>
#include <wx/wx.h>
#include "../Spreadsheet.h"

int main(int argc, char *argv[]){
    wxEntryStart(argc, argv);
    wxTheApp->CallOnInit();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}