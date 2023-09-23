//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include "../Spreadsheet.h"

TEST(SpreadsheetSuite, SpreadsheetConstructorTest) {
    auto ptr = new Spreadsheet(-1, 2, NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr->getRows(), 1);
    EXPECT_EQ(ptr->getColumns(), 2);
    EXPECT_EQ(ptr->getCells().size(), 2);
    auto ptr2 = new Spreadsheet(1, -4, NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr2->getRows(), 1);
    EXPECT_EQ(ptr2->getColumns(), 2);
    EXPECT_EQ(ptr2->getCells().size(), 2);
}

TEST(SpreadsheetSuite, areLegalCellCoordinatesTest) {
    auto ptr = new Spreadsheet(5, 5, NULL, wxID_ANY, "Spreadsheet");
    EXPECT_TRUE(ptr->areLegalCellCoordinates(2, 3));
    EXPECT_TRUE(ptr->areLegalCellCoordinates(0, 0));
    EXPECT_TRUE(ptr->areLegalCellCoordinates(4, 4));
    EXPECT_FALSE(ptr->areLegalCellCoordinates(-2, -3));
    EXPECT_FALSE(ptr->areLegalCellCoordinates(10, 20));
}

TEST(SpreadsheetSuite, setObserveHorizontalTest) {
    auto ptr = new Spreadsheet(1, 5, NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverHorizontal(0, 4, FormulaType::sum);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(ptr->getCells()[i]->getObservers().size(), 1);
    }
    EXPECT_EQ(ptr->getCells()[4]->getSubjects().size(), 4);
    EXPECT_TRUE(typeid(*(ptr->getCells()[4]->getFormula())) == typeid(SumFormula));
    EXPECT_FALSE(ptr->setObserverHorizontal(-2, -3, FormulaType::sum));
}

TEST(SpreadsheetSuite, setObserveVerticalTest) {
    auto ptr = new Spreadsheet(5, 2, NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverVertical(4, 0, FormulaType::sum);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(ptr->getCells()[i * ptr->getColumns()]->getObservers().size(), 1);
    }
    EXPECT_EQ(ptr->getCells()[8]->getSubjects().size(), 4);
    EXPECT_TRUE(typeid(*(ptr->getCells()[8]->getFormula())) == typeid(SumFormula));
    EXPECT_FALSE(ptr->setObserverVertical(-2, -3, FormulaType::sum));
}

TEST(SpreadsheetSuite, removeObserverTest) {
    auto ptr = new Spreadsheet(1, 5, NULL, wxID_ANY, "Spreadsheet");
    ptr->setObserverHorizontal(0, 4, FormulaType::sum);
    ptr->removeObserver(0, 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(ptr->getCells()[i]->getObservers().size(), 0);
    }
    EXPECT_EQ(ptr->getCells()[4]->getSubjects().size(), 0);
    EXPECT_TRUE(ptr->getCells()[4]->getFormula() == nullptr);
    EXPECT_FALSE(ptr->removeObserver(-2, -3));
}

TEST(SpreadsheetSuite, changeFormulaTest) {
    auto ptr = new Spreadsheet(5, 5, NULL, wxID_ANY, "Spreadsheet");
    EXPECT_TRUE(ptr->getCells()[4]->getFormula() == nullptr);
    ptr->changeFormula(0, 4, sum);
    EXPECT_TRUE(typeid(*(ptr->getCells()[4]->getFormula())) == typeid(SumFormula));
    ptr->changeFormula(0, 4, max);
    EXPECT_TRUE(typeid(*(ptr->getCells()[4]->getFormula())) == typeid(MaxFormula));
    ptr->changeFormula(0, 4, min);
    EXPECT_TRUE(typeid(*(ptr->getCells()[4]->getFormula())) == typeid(MinFormula));
    ptr->changeFormula(0, 4, mean);
    EXPECT_TRUE(typeid(*(ptr->getCells()[4]->getFormula())) == typeid(MeanFormula));
}