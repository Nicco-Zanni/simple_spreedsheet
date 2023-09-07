//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include <wx/wx.h>
#include "../Spreadsheet.h"
#include "../Cell.h"

TEST(CellSuite, CellConstructorTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    EXPECT_EQ(ptr->getValue(), 0);
    EXPECT_EQ(ptr->getFormula(), "none");
    EXPECT_EQ(ptr->getSubjects().size(), 0);
    EXPECT_EQ(ptr->getObservers().size(), 0);
    EXPECT_EQ(ptr->getTextCtrl(), text);
}