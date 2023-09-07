//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include "../Spreadsheet.h"

TEST(SpreadsheetSuite, testSpreadsheetConstructor){
    auto ptr = new Spreadsheet(-1, 2,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr->getRows(), 1);
    EXPECT_EQ(ptr->getColumns(), 2);
    EXPECT_EQ(ptr->getCells().size(), 2);
    auto ptr2 = new Spreadsheet(1, -4,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr2->getRows(), 1);
    EXPECT_EQ(ptr2->getColumns(), 2);
    EXPECT_EQ(ptr2->getCells().size(), 2);
}