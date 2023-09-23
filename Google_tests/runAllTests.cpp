//
// Created by nicco on 23/09/23.
//
#include <gtest/gtest.h>
#include <wx/wx.h>
#include "../Spreadsheet.h"
#include "../main.h"

IMPLEMENT_APP_NO_MAIN(MyApp)

int main(int argc, char *argv[]) {
    wxEntryStart(argc, argv);
    auto ptr = dynamic_cast<MyApp *>(wxTheApp);
    ptr->CallOnInit();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool MyApp::OnInit() {
    frame = new Spreadsheet(5, 5, NULL, wxID_ANY, "Spreadsheet");
    return true;
}