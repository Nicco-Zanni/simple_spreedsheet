//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include "../Spreadsheet.h"

TEST(SpreadsheetSuite, SpreadsheetConstructorTest){
    auto ptr = new Spreadsheet(-1, 2,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr->getRows(), 1);
    EXPECT_EQ(ptr->getColumns(), 2);
    EXPECT_EQ(ptr->getCells().size(), 2);
    auto ptr2 = new Spreadsheet(1, -4,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr2->getRows(), 1);
    EXPECT_EQ(ptr2->getColumns(), 2);
    EXPECT_EQ(ptr2->getCells().size(), 2);
}

TEST(SpreadsheetSuite, setObserveHorizontalTest){
    auto ptr = new Spreadsheet(1, 5,NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverHorizontal(0, 4, "sum");
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(ptr->getCells()[i]->getObservers().size(), 1);
    }
    EXPECT_EQ(ptr->getCells()[4]->getSubjects().size(), 4);
    EXPECT_EQ(ptr->getCells()[4]->getFormula(), "sum");
}

TEST(SpreadsheetSuite, setObserveVerticalTest){
    auto ptr = new Spreadsheet(5, 2,NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverVertical(4, 0, "sum");
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(ptr->getCells()[i*ptr->getColumns()]->getObservers().size(), 1);
    }
    EXPECT_EQ(ptr->getCells()[15]->getSubjects().size(), 4);
    EXPECT_EQ(ptr->getCells()[15]->getFormula(), "sum");
}

TEST(SpreadsheetSuite, removeObserverTest){
    auto ptr = new Spreadsheet(1, 5,NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverHorizontal(0, 4, "sum");
    ptr->removeObserver(0, 4);
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(ptr->getCells()[i]->getObservers().size(), 0);
    }
    EXPECT_EQ(ptr->getCells()[4]->getSubjects().size(), 0);
    EXPECT_EQ(ptr->getCells()[4]->getFormula(), "none");
}