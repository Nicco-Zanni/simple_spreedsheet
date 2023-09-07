//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include "../Spreadsheet.h"

TEST(SpreadsheetSuite, testSetGridSize){
    auto ptr = dynamic_cast<Spreadsheet *> (wxTheApp->GetTopWindow());
    ptr->setGridSize(-1, 2);
    EXPECT_EQ(ptr->getRows(), 1);
    EXPECT_EQ(ptr->getColumns(), 2);
    ptr->setGridSize(1, -5);
    EXPECT_EQ(ptr->getRows(), 1);
    EXPECT_EQ(ptr->getColumns(), 2);
}