/*
 * LogicGates.h
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 *
 * update by Shaohai Li and add a NOT gate class and XOR gate class
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
    /**
     * Constructor for concrete class NAND.
     */
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
    /**
     * Constructor for concrete class OR.
     */
    OR(const unsigned short int);
    virtual ~OR();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

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

class XOR: public AbstractGate
{
public:
    /**
     * Constructor for concrete class XOR.
     */
    XOR(const unsigned short int);
    virtual ~XOR();

protected:
    std::string m_strID;
    NAND m_nand1, m_nand2, m_nand3, m_nand4;

    virtual void update();
    virtual std::string repr();
};

#endif /* _LOGICGATES_H_ */