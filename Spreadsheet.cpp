//
// Created by nicco on 25/08/23.
//

#include "Spreadsheet.h"
#include <wx/wx.h>

Spreadsheet::Spreadsheet(int numOfColumns, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                         const wxSize &size, long style, const wxString &name) : wxFrame(parent, id, title, pos, size,
                                                                                         style, name){
    if(numOfColumns < 2)
        columns = 1;
    else
        columns = numOfColumns;
    wxFont font(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    this->SetFont(font);
    setupGrid();
    Bind(wxEVT_TEXT, &Spreadsheet::notify, this);
}

void Spreadsheet::setupGrid() {
    auto sizer = new wxBoxSizer(wxVERTICAL);
    auto panel = new wxScrolled<wxPanel>(this, wxID_ANY);
    auto panelSizer = new wxBoxSizer(wxVERTICAL);

    auto gridSizerCells = new wxGridSizer(rows, columns, 0, 0);
    panel->SetScrollRate(5, 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            auto cell = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER | wxTE_CENTRE, wxTextValidator(wxFILTER_NUMERIC));
            gridSizerCells->Add(cell, 1, wxALL | wxEXPAND, 0);
            cells.push_back(cell);
            //cell->Bind(wxEVT_TEXT, &Spreadsheet::notify, this);
        }
        auto result = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                     wxTE_READONLY | wxTE_CENTRE);
        gridSizerCells->Add(result, 1, wxALL | wxEXPAND, 0);
        cells.push_back(result);
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
   observers.clear();
   Unbind(wxEVT_TEXT, &Spreadsheet::notify, this);
}

double Spreadsheet::getCellValueAt(int x, int y) const {
    if(!isEmpty(x, y) && isLegalCharacter(x, y))
        return std::stod(cells[x * columns + y]->GetValue().ToStdString());
    else
        return 0;
}

void Spreadsheet::setResult(double result, int x, int y) {
    cells[x * columns + y]->ChangeValue(wxString::Format(wxT("%f"), result));
}

bool Spreadsheet::isEmpty(int x, int y) const {
    if(cells[x * columns + y]->GetValue() == wxEmptyString)
        return true;
    return false;
}

bool Spreadsheet::isLegalCharacter(int x, int y) const {
    if(cells[x * columns + y]->GetValue() != wxT("-") && cells[x * columns + y]->GetValue() != wxT("+") && cells[x * columns + y]->GetValue() != wxT("e"))
        return true;
    return false;
}
