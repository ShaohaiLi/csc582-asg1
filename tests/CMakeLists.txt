# Enable testing for this directory
enable_testing()

# Find Google Test package
find_package(GTest REQUIRED)

# Include directories
include_directories($ {GTEST_INCLUDE_DIRS})
include_directories($ {CMAKE_SOURCE_DIR}/source/FourBitAdder)
include_directories($ {CMAKE_SOURCE_DIR}/source/FourBitAdder/intern)

set(TEST_SOURCES
    gtests/GTestLogicGates.cpp
    gtests/GTestHalfAdder.cpp
    gtests/GTestFullAdder.cpp
    gtests/GTestFourBitAdder.cpp
   )

add_executable(run_all_tests $ {TEST_SOURCES})

target_link_libraries(run_all_tests
                      GTest::GTest
                      GTest::Main
                      FourBitAdder
                      pthread
                     )

add_test(NAME AllTests COMMAND run_all_tests)

# Remove this line if you don't have a separate CMakeLists.txt in the gtests directory
# add_subdirectory(gtests)