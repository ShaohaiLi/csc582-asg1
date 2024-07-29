cmake_minimum_required(VERSION 3.10)

add_subdirectory(FourBitAdder)

# Include directories
include_directories(
    $ {CMAKE_CURRENT_SOURCE_DIR}
    $ {CMAKE_CURRENT_SOURCE_DIR}/FourBitAdder
    $ {CMAKE_CURRENT_SOURCE_DIR}/FourBitAdder/intern
)

# Define the source files
set(SOURCE_FILES
    FourBitAdder/FourBitAdder.h
    FourBitAdder/intern/FourBitAdder.cpp
    FourBitAdder/intern/LogicGates.h
    FourBitAdder/intern/LogicGates.cpp
    FourBitAdder/intern/AbstractGate.h
    FourBitAdder/intern/AbstractGate.cpp
   )

# Create the library
add_library(FourBitAdderLib $ {SOURCE_FILES})

# Set properties for the target
set_target_properties(FourBitAdderLib PROPERTIES
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON
                     )

target_include_directories(FourBitAdder PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/intern
)