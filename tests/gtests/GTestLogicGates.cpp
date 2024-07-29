#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/LogicGates.h"

TEST(ANDConstructorTest, test001) {
    AND and1(1);
    ASSERT_EQ(and1.in1(), 0);
    ASSERT_EQ(and1.in2(), 0);
    ASSERT_EQ(and1.out(), 0);
}

TEST(NANDConstructorTest, test002) {
    NAND nand1(1);
    ASSERT_EQ(nand1.in1(), 0);
    ASSERT_EQ(nand1.in2(), 0);
    ASSERT_EQ(nand1.out(), 0);
}

TEST(ORConstructorTest, test003) {
    OR or1(1);
    ASSERT_EQ(or1.in1(), 0);
    ASSERT_EQ(or1.in2(), 0);
    ASSERT_EQ(or1.out(), 0);
}

TEST(ORTruthTableTest, test004) {
    OR or1(1);
    const unsigned short int bits[2] = {0, 1};
    for (int idx = 0; idx < 2; idx++) {
        for (int idx2 = 0; idx2 < 2; idx2++) {
            or1.set_in1(bits[idx]);
            or1.set_in2(bits[idx2]);
            ASSERT_EQ(bits[idx] | bits[idx2], or1.out());
        }
    }
}

TEST(NOTConstructorTest, test005) {
    NOT not1(1);
    ASSERT_EQ(not1.in1(), 0);
    ASSERT_EQ(not1.out(), 1);  // NOT gate should invert 0 to 1 by default
}

TEST(XORConstructorTest, test006) {
    XOR xor1(1);
    ASSERT_EQ(xor1.in1(), 0);
    ASSERT_EQ(xor1.in2(), 0);
    ASSERT_EQ(xor1.out(), 0);
}

TEST(NOTTruthTableTest, test007) {
    NOT not1(1);
    not1.set_in1(0);
    ASSERT_EQ(1, not1.out());
    not1.set_in1(1);
    ASSERT_EQ(0, not1.out());
}

TEST(XORTruthTableTest, test008) {
    XOR xor1(1);
    const unsigned short int bits[2] = {0, 1};
    for (int idx = 0; idx < 2; idx++) {
        for (int idx2 = 0; idx2 < 2; idx2++) {
            xor1.set_in1(bits[idx]);
            xor1.set_in2(bits[idx2]);
            ASSERT_EQ(bits[idx] ^ bits[idx2], xor1.out());
        }
    }
}