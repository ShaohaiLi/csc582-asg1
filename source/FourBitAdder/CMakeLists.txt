# List of header files
set(INC
    FourBitAdder.h
    intern/LogicGates.h
    intern/AbstractGate.h
)

# List of source files
set(SRC
    intern/FourBitAdder.cpp
    intern/LogicGates.cpp
    intern/AbstractGate.cpp
)

add_library(FourBitAdder ${INC} ${SRC})

# Specify include directories for this target
target_include_directories(FourBitAdder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(intern)