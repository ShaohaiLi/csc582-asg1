/*
 * LogicGates.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 * Shaohai Li add NOT and XOR gates
 */

#include "../../FourBitAdder/intern/LogicGates.h"
#include <string>

/**** AND ****/

AND::AND(const unsigned short int id)
{
    m_strID = std::to_string(id) + "AND";
}

AND::~AND()
{
}

void AND::update()
{
    m_usiOut = m_usiIn1 && m_usiIn2;
}

std::string AND::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}

/**** NAND ****/

NAND::NAND(const unsigned short int id)
{
    m_strID = std::to_string(id) + "NAND";
}

NAND::~NAND()
{
}

void NAND::update()
{
    m_usiOut = !(m_usiIn1 && m_usiIn2);
}

std::string NAND::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}

/**** OR ****/

OR::OR(const unsigned short int id)
{
    m_strID = std::to_string(id) + "OR";
}

OR::~OR()
{
}

void OR::update()
{
    m_usiOut = m_usiIn1 || m_usiIn2;
}

std::string OR::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}

/**** NOT ****/

NOT::NOT(const unsigned short int id) : m_nand(id)
{
    m_strID = std::to_string(id) + "NOT";
    m_usiIn1 = 0;
    update();
}

NOT::~NOT()
{
}

void NOT::update()
{
    m_nand.set_in1(m_usiIn1);
    m_nand.set_in2(m_usiIn1);
    m_usiOut = m_nand.out();
}

std::string NOT::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}

/**** XOR ****/

XOR::XOR(const unsigned short int id) : m_nand1(id), m_nand2(id), m_nand3(id), m_nand4(id)
{
    m_strID = std::to_string(id) + "XOR";
}

XOR::~XOR()
{
}

void XOR::update()
{
    m_nand1.set_in1(m_usiIn1);
    m_nand1.set_in2(m_usiIn2);

    m_nand2.set_in1(m_usiIn1);
    m_nand2.set_in2(m_nand1.out());

    m_nand3.set_in1(m_nand1.out());
    m_nand3.set_in2(m_usiIn2);

    m_nand4.set_in1(m_nand2.out());
    m_nand4.set_in2(m_nand3.out());

    m_usiOut = m_nand4.out();
}

std::string XOR::repr()
{
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}