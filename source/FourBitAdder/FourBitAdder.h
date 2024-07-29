/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.

#ifndef _FOURBITADDER_H_
#define _FOURBITADDER_H_

#include "intern/LogicGates.h"

// Half-adder circuit
class HalfAdder {
private:
    XOR m_xor;
    AND m_and;

public:
    HalfAdder();
    void set_inputs(unsigned short int a, unsigned short int b);
    unsigned short int get_sum() const;
    unsigned short int get_carry() const;
};

// Full-adder circuit
class FullAdder {
private:
    HalfAdder m_ha1, m_ha2;
    OR m_or;

public:
    FullAdder();
    void set_inputs(unsigned short int a, unsigned short int b, unsigned short int cin);
    unsigned short int get_sum() const;
    unsigned short int get_carry() const;
};

// Four-bit adder
class FourBitAdder {
private:
    FullAdder m_fullAdders[4];
    unsigned short int m_sum;
    unsigned short int m_carry;

public:
    FourBitAdder();
    ~FourBitAdder();

    void set_inputs(unsigned short int a, unsigned short int b);
    unsigned short int get_sum() const;
    unsigned short int get_carry() const;
};

#endif // _FOURBITADDER_H_