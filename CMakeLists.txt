cmake_minimum_required(VERSION 3.26)
project(simple_spreadsheet)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED net gl core base xrc adv)
include(${wxWidgets_USE_FILE})

add_executable(simple_spreadsheet main.cpp
        Spreadsheet.cpp
        Spreadsheet.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
