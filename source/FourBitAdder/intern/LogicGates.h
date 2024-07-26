/*
 * LogicGates.h
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 *
 * update by Shaohai Li and add a NOT gate clas
 */

#ifndef _LOGICGATES_H_
#define _LOGICGATES_H_

#include <string>
#include "../../FourBitAdder/intern/AbstractGate.h"

class AND: public AbstractGate
{
public:
    /**
     * Constructor for concrete class AND.
     */
    AND(const unsigned short int);
    virtual ~AND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class NAND: public AbstractGate
{
public:
    NAND(const unsigned short int);
    virtual ~NAND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class OR: public AbstractGate
{
public:
    OR(const unsigned short int);
    virtual ~OR();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

// Add the NOT gate class
class NOT: public AbstractGate
{
public:
    /**
     * Constructor for concrete class NOT.
     */
    NOT(const unsigned short int);
    virtual ~NOT();

protected:
    std::string m_strID;
    NAND m_nand; // Use NAND gate to implement NOT

    virtual void update();
    virtual std::string repr();
};

// You might also want to add an XOR gate for the half adder
class XOR: public AbstractGate
{
public:
    XOR(const unsigned short int);
    virtual ~XOR();

protected:
    std::string m_strID;
    // You'll need to implement XOR using the other gates
    NAND m_nand1, m_nand2, m_nand3, m_nand4;

    virtual void update();
    virtual std::string repr();
};

#endif /* _LOGICGATES_H_ */


