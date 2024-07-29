# Enable testing for this directory
enable_testing()

# Find Google Test package
find_package(GTest REQUIRED)

# Include directories
include_directories($ {GTEST_INCLUDE_DIRS})
include_directories($ {CMAKE_SOURCE_DIR}/source/FourBitAdder)
include_directories($ {CMAKE_SOURCE_DIR}/source/FourBitAdder/intern)

# Add all test files
set(TEST_SOURCES
    gtests/GTestLogicGates.cpp
    gtests/GTestHalfAdder.cpp
    gtests/GTestFullAdder.cpp
    gtests/GTestFourBitAdder.cpp
   )

add_subdirectory(gtests)

# Create test executable
add_executable(run_all_tests
               gtests/GTestLogicGates.cpp
               gtests/GTestHalfAdder.cpp
               gtests/GTestFullAdder.cpp
               gtests/GTestFourBitAdder.cpp
              )

# Link the test executable with Google Test and your project libraries
target_link_libraries(run_tests
                      GTest::GTest
                      GTest::Main
                      proj1_FourBitAdder
                     )

# Add tests to be run by CTest
add_test(NAME AllTests COMMAND run_tests)


