# Build FourBitAdder
set(SRC
    AbstractGate.cpp
    LogicGates.cpp
    FourBitAdder.cpp
   )

set(INC
    AbstractGate.h
    LogicGates.h
   )

add_library(proj1_FourBitAdder SHARED "${SRC}" "${INC}")

# Specify include directories for this target
target_include_directories(proj1_FourBitAdder PUBLIC $ {CMAKE_CURRENT_SOURCE_DIR})


# Set properties for the target (optional)
set_target_properties(proj1_FourBitAdder PROPERTIES
                      VERSION 1.0.0
                      SOVERSION 1
                      PUBLIC_HEADER "${INC}"
                     )

# Install rules
install(TARGETS proj1_FourBitAdder
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
       )