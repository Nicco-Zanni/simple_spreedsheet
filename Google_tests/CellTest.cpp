//
// Created by nicco on 07/09/23.
//
#include <gtest/gtest.h>
#include <wx/wx.h>
#include "../Spreadsheet.h"
#include "../Cell.h"
#include "../main.h"

TEST(CellSuite, CellConstructorTest){
    auto ptr = new Spreadsheet(5, 5,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_EQ(ptr->getCells()[8]->getValue(), 0);
    EXPECT_EQ(ptr->getCells()[8]->getFormula(), "none");
    EXPECT_EQ(ptr->getCells()[8]->getSubjects().size(), 0);
    EXPECT_EQ(ptr->getCells()[8]->getObservers().size(), 0);
}

TEST(CellSuite, isLegalCharacterTest){
    auto ptr = new Spreadsheet(5, 5,NULL, wxID_ANY, "Spreadsheet");
    ptr->getCells()[8]->getTextCtrl()->SetValue("-");
    EXPECT_FALSE(ptr->getCells()[8]->isLegalCharacter());
    ptr->getCells()[8]->getTextCtrl()->SetValue("+");
    EXPECT_FALSE(ptr->getCells()[8]->isLegalCharacter());
    ptr->getCells()[8]->getTextCtrl()->SetValue("5");
    EXPECT_TRUE(ptr->getCells()[8]->isLegalCharacter());
}

TEST(CellSuite, isEmptyTest){
    auto ptr = new Spreadsheet(5, 5,NULL, wxID_ANY, "Spreadsheet");
    EXPECT_TRUE(ptr->getCells()[10]->isEmpty());
    ptr->getCells()[10]->getTextCtrl()->SetValue("5");
    EXPECT_FALSE(ptr->getCells()[10]->isEmpty());
}

TEST(CellSuite, SetValue){
    auto ptr = new Spreadsheet(5, 5,NULL, wxID_ANY, "Spreadsheet");
    ptr->getCells()[12]->getTextCtrl()->SetValue("3");
    ptr->getCells()[12]->setValue();
    EXPECT_FLOAT_EQ(ptr->getCells()[12]->getValue(), 3);
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

TEST(CellSuite, updateSumTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text3 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text2);
    auto ptr3 = new Cell(text3);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    ptr->setFormula("sum");
    text2->ChangeValue("3");
    ptr2->setValue();
    text3->ChangeValue("4");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 7);
    text2->ChangeValue("-5");
    ptr2->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -1);
}

TEST(CellSuite, updateMaxTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text3 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text2);
    auto ptr3 = new Cell(text3);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    ptr->setFormula("max");
    text2->ChangeValue("3");
    ptr2->setValue();
    text3->ChangeValue("4");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 4);
    text2->ChangeValue("-5");
    ptr2->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 4);
    text3->ChangeValue("-6");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -5);
}

TEST(CellSuite, updateMinTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text3 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text2);
    auto ptr3 = new Cell(text3);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    ptr->setFormula("min");
    text2->ChangeValue("3");
    ptr2->setValue();
    text3->ChangeValue("4");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 3);
    text2->ChangeValue("-5");
    ptr2->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -5);
    text3->ChangeValue("-6");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -6);
}

TEST(CellSuite, updateMeanTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text3 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text2);
    auto ptr3 = new Cell(text3);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    ptr->setFormula("mean");
    text2->ChangeValue("3");
    ptr2->setValue();
    text3->ChangeValue("4");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 3.5);
    text2->ChangeValue("-5");
    ptr2->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -0.5);
    text3->ChangeValue("-6");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), -5.5);
}

TEST(CellSuite, updateNoneTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text2 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto text3 = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    auto ptr2 = new Cell(text2);
    auto ptr3 = new Cell(text3);
    ptr2->subscribe(ptr);
    ptr3->subscribe(ptr);
    ptr->addSubject(ptr2);
    ptr->addSubject(ptr3);
    ptr->setFormula("ienviai");
    text2->ChangeValue("3");
    ptr2->setValue();
    text3->ChangeValue("4");
    ptr3->setValue();
    ptr->update();
    EXPECT_FLOAT_EQ(ptr->getValue(), 0);
}

TEST(CellSuite, setResultTest){
    auto text = new wxTextCtrl(NULL, wxID_ANY, "0");
    auto ptr = new Cell(text);
    ptr->setResult();
    EXPECT_EQ(text->GetValue(), "0");
    ptr->changeValue(3);
    ptr->setResult();
    EXPECT_EQ(text->GetValue(), "3");
}