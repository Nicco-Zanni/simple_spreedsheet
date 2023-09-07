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

TEST(CellSuite, isLegalCharacterTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "-");
    auto ptr = new Cell(text);
    EXPECT_FALSE(ptr->isLegalCharacter());
    text->ChangeValue("+");
    EXPECT_FALSE(ptr->isLegalCharacter());
    text->ChangeValue("0");
    EXPECT_TRUE(ptr->isLegalCharacter());
}

TEST(CellSuite, isEmptyTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, wxEmptyString);
    auto ptr = new Cell(text);
    EXPECT_TRUE(ptr->isEmpty());
    text->ChangeValue("0");
    EXPECT_FALSE(ptr->isEmpty());
}