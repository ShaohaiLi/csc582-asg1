cmake_minimum_required (VERSION 3.10)

#https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
#https://github.com/google/googletest/blob/master/googletest/docs/primer.md

# Find Google Test package
find_package(GTest REQUIRED)
include_directories($ {GTEST_INCLUDE_DIRS})

# Include directories for your project files
include_directories(
    $ {CMAKE_SOURCE_DIR}/source/FourBitAdder
    $ {CMAKE_SOURCE_DIR}/source/FourBitAdder/intern
)

# Set include files
set(INC_FILES
    $ {CMAKE_SOURCE_DIR}/source/FourBitAdder/intern/AbstractGate.h
    $ {CMAKE_SOURCE_DIR}/source/FourBitAdder/intern/LogicGates.h
    $ {CMAKE_SOURCE_DIR}/source/FourBitAdder/FourBitAdder.h
   )

# Set source files for all tests
set(TEST_SOURCES
    GTestLogicGates.cpp
    GTestHalfAdder.cpp
    GTestFullAdder.cpp
    GTestFourBitAdder.cpp
   )

# Create executables for each test file
foreach(test_source $ {TEST_SOURCES})
    get_filename_component(test_name $ {test_source} NAME_WE)
    add_executable($ {test_name} $ {test_source} $ {INC_FILES})
    target_link_libraries($ {test_name}
                          GTest::GTest
                          GTest::Main
                          FourBitAdder
                          pthread
                         )
    add_test(NAME $ {test_name} COMMAND $ {test_name})
    endforeach()

# Create a single executable for all tests
    add_executable(run_all_tests $ {TEST_SOURCES} $ {INC_FILES})
    target_link_libraries(run_all_tests
                          GTest::GTest
                          GTest::Main
                          FourBitAdder
                          pthread
                         )
    add_test(NAME AllTests COMMAND run_all_tests)