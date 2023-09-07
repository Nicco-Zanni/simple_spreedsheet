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

TEST(CellSuite, subscribeTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text);
    auto ptr3 = new Cell(text);
    ptr->subscribe(ptr2);
    ptr->subscribe(ptr3);
    EXPECT_EQ(ptr->getObservers().size(), 2);
    EXPECT_EQ(ptr->getObservers().front(), ptr2);
}

TEST(CellSuite, unsubscribeTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text);
    auto ptr3 = new Cell(text);
    ptr->subscribe(ptr2);
    ptr->subscribe(ptr3);
    ptr->unsubscribe(ptr2);
    ptr->unsubscribe(ptr3);
    EXPECT_EQ(ptr->getObservers().size(), 0);
}

TEST(CellSuite, addAndRemoveSubjectsTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text);
    auto ptr3 = new Cell(text);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    EXPECT_EQ(ptr->getSubjects().size(), 2);
    ptr->removeSubjects();
    EXPECT_EQ(ptr->getSubjects().size(), 0);
}

TEST(CellSuite, SetValue){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "3");
    auto ptr = new Cell(text);
    ptr->setValue();
    EXPECT_FLOAT_EQ(ptr->getValue(), 3);
}

TEST(CellSuite, notifyTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text);
    auto ptr3 = new Cell(text2);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    text->SetValue("3");
    EXPECT_FLOAT_EQ(ptr2->getValue(), 3);
    EXPECT_FLOAT_EQ(ptr->getValue(), 0);
}