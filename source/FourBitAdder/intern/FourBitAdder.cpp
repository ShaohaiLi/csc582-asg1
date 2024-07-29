/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.

#include "../FourBitAdder.h"
#include "LogicGates.h"

// HalfAdder implementation
HalfAdder::HalfAdder() : m_xor(1), m_and(1) {}

void HalfAdder::set_inputs(unsigned short int a, unsigned short int b) {
    m_xor.set_in1(a);
    m_xor.set_in2(b);
    m_and.set_in1(a);
    m_and.set_in2(b);
}

unsigned short int HalfAdder::get_sum() const {
    return m_xor.out();
}
unsigned short int HalfAdder::get_carry() const {
    return m_and.out();
}

// FullAdder implementation
FullAdder::FullAdder() : m_or(1) {}

void FullAdder::set_inputs(unsigned short int a, unsigned short int b, unsigned short int cin) {
    m_ha1.set_inputs(a, b);
    m_ha2.set_inputs(m_ha1.get_sum(), cin);
    m_or.set_in1(m_ha1.get_carry());
    m_or.set_in2(m_ha2.get_carry());
}

unsigned short int FullAdder::get_sum() const {
    return m_ha2.get_sum();
}
unsigned short int FullAdder::get_carry() const {
    return m_or.out();
}

// FourBitAdder implementation
FourBitAdder::FourBitAdder() : m_sum(0), m_carry(0) {}

FourBitAdder::~FourBitAdder() {}

void FourBitAdder::set_inputs(unsigned short int a, unsigned short int b) {
    FullAdder fa[4];
    unsigned short int carry = 0;
    m_sum = 0;

    for (int i = 0; i < 4; i++) {
        unsigned short int bit_a = (a >> i) & 1;
        unsigned short int bit_b = (b >> i) & 1;
        fa[i].set_inputs(bit_a, bit_b, carry);
        m_sum |= (fa[i].get_sum() << i);
        carry = fa[i].get_carry();
    }

    m_carry = carry;
}

unsigned short int FourBitAdder::get_sum() const {
    return m_sum;
}

unsigned short int FourBitAdder::get_carry() const {
    return m_carry;
}