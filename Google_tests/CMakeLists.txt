cmake_minimum_required(VERSION 3.8)
add_subdirectory(lib)
include(${wxWidgets_USE_FILE})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(files ../Spreadsheet.cpp ../Spreadsheet.h ../Cell.cpp ../Cell.h ../main.h ../SumFormula.h ../SumFormula.cpp
        ../MaxFormula.h ../MaxFormula.cpp ../MinFormula.h ../MinFormula.cpp ../MeanFormula.h ../MeanFormula.cpp
)
add_executable(Google_Test_run
        TestSpreasheet.cpp
        CellTest.cpp
        ${files}
        FormulaTest.cpp
        runAllTests.cpp
)
target_link_libraries(Google_Test_run gtest gtest_main)
target_link_libraries(Google_Test_run ${wxWidgets_LIBRARIES} ${SOURCE_FILES})