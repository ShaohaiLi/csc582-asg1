
# List of header files
set(INC
    FourBitAdder.h
    intern/LogicGates.h
    intern/AbstractGate.h
   )

# List of source filesaC
set(SRC
    intern/FourBitAdder.cpp
    intern/LogicGates.cpp
    intern/AbstractGate.cpp
   )

add_library(FourBitAdder $ {INC} $ {SRC})

add_subdirectory(intern)