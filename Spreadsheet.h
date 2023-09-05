//
// Created by nicco on 25/08/23.
//

#ifndef SIMPLE_SPREADSHEET_SPREADSHEET_H
#define SIMPLE_SPREADSHEET_SPREADSHEET_H

#include <wx/frame.h>
#include <vector>
#include "Cell.h"


class Spreadsheet: public wxFrame{
public:
    explicit Spreadsheet(int numOfRows, int numOfColumns, wxWindow *parent = nullptr, wxWindowID id = wxID_ANY,
                         const wxString &title = wxEmptyString, const wxPoint &pos = wxDefaultPosition,
                         const wxSize &size = wxDefaultSize,
                         long style = wxDEFAULT_FRAME_STYLE, const wxString &name = wxFrameNameStr);


    ~Spreadsheet() override;

    void setObserverHorizontal(int row, int column, const std::string& formula);

    void removeObserver(int row, int column);

    void setObserverVertical(int row, int column, const std::string& formula);

    void changeFormula(int row, int column, const std::string& formula);

private:
    int rows, columns;
    std::vector<Cell*> cells;
    void setupGrid();
    void setGridSize(int numOfRows, int numOfColumns);
    bool areLegalCellCoordinates(int x, int y) const;
};


#endif //SIMPLE_SPREADSHEET_SPREADSHEET_H
