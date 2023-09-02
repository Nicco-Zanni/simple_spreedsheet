//
// Created by nicco on 25/08/23.
//

#include "Spreadsheet.h"
#include <wx/wx.h>

Spreadsheet::Spreadsheet(int numOfRows, int numOfColumns, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                         const wxSize &size, long style, const wxString &name) : wxFrame(parent, id, title, pos, size,
                                                                                         style, name){
    if(numOfRows < 1){
        rows = 1;
    }else{
        rows = numOfRows;
    }
    if(numOfColumns < 2){
        columns = 2;
    }else{
        columns = numOfColumns;
    }
    wxFont font(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    this->SetFont(font);
    setupGrid();
}

void Spreadsheet::setupGrid() {
    auto sizer = new wxBoxSizer(wxVERTICAL);
    auto panel = new wxScrolled<wxPanel>(this, wxID_ANY);
    auto panelSizer = new wxBoxSizer(wxVERTICAL);

    auto gridSizerCells = new wxGridSizer(rows, columns, 0, 0);
    panel->SetScrollRate(5, 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            auto textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER | wxTE_CENTRE, wxTextValidator(wxFILTER_NUMERIC));
            gridSizerCells->Add(textCtrl, 1, wxALL | wxEXPAND, 0);
            cells.push_back(new Cell(i, j, textCtrl ));
        }
    }

    auto top_panel = new wxPanel(this, wxID_ANY);
    auto bottom_panel = new wxPanel(this, wxID_ANY);

    panelSizer->Add(top_panel, 1, wxALL | wxEXPAND, 5);
    panelSizer->Add(gridSizerCells, 0, wxALL | wxEXPAND, 5);
    panelSizer->Add(bottom_panel, 1, wxALL | wxEXPAND, 5);
    panel->SetSizerAndFit(panelSizer);
    sizer->Add(panel, 1, wxALL | wxEXPAND, 5);
    SetSizerAndFit(sizer);
}

Spreadsheet::~Spreadsheet() {
   cells.clear();
}


