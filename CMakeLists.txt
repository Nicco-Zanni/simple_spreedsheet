cmake_minimum_required(VERSION 3.26)
project(simple_spreadsheet)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})
add_subdirectory(Google_tests)
set(SOURCE_FILES main.cpp Spreadsheet.cpp Spreadsheet.h Observer.h Subject.h Cell.cpp Cell.h
        main.h
        Formula.h
        SumFormula.cpp
        SumFormula.h
        MaxFormula.cpp
        MaxFormula.h
        MinFormula.cpp
        MinFormula.h
        MeanFormula.cpp
        MeanFormula.h
)
add_executable(simple_spreadsheet main.cpp
        Spreadsheet.cpp
        Spreadsheet.h
        Observer.h
        Subject.h
        Cell.cpp
        Cell.h
        SumFormula.cpp
        SumFormula.h
        MaxFormula.cpp
        MaxFormula.h
        MinFormula.cpp
        MinFormula.h
        MeanFormula.cpp
        MeanFormula.h
)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
