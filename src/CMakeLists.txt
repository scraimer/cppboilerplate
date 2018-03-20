cmake_minimum_required (VERSION 3.2)

project (cppboilerplate)

#write_compiler_detection_header(
#  FILE "${CMAKE_CURRENT_BINARY_DIR}/cppboilerplate_compiler_detection.h"
#  PREFIX cppboilerplate
#  COMPILERS GNU
#  FEATURES
#    cxx_final cxx_override
#)

include_directories ("${PROJECT_SOURCE_DIR}/raii_socket")
add_subdirectory (raii_socket) 
set (EXTRA_LIBS ${EXTRA_LIBS} raii_socket)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
target_link_libraries (main ${EXTRA_LIBS})

include(CTest)

# does the application run
add_test (mainRuns main 25)
# does it sqrt of 25
add_test (mainComp25 main 25)
set_tests_properties (mainComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
# does it handle negative numbers
add_test (mainNegative main -25)
set_tests_properties (mainNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
# does it handle small numbers
add_test (mainSmall main 0.0001)
set_tests_properties (mainSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
# does the usage message work?
add_test (mainUsage main)
set_tests_properties (mainUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
