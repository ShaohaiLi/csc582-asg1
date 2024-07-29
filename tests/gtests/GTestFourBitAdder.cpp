#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"

class FourBitAdderTest : public ::testing::Test {
protected:
    FourBitAdder adder;
};

TEST_F(FourBitAdderTest, ZeroPlusZero) {
    adder.set_inputs(0, 0);
    EXPECT_EQ(adder.get_sum(), 0);
    EXPECT_EQ(adder.get_carry(), 0);
}

TEST_F(FourBitAdderTest, OnePlusOne) {
    adder.set_inputs(1, 1);
    EXPECT_EQ(adder.get_sum(), 2);
    EXPECT_EQ(adder.get_carry(), 0);
}

TEST_F(FourBitAdderTest, MaxValuePlusOne) {
    adder.set_inputs(15, 1);  // 15 is 1111 in binary
    EXPECT_EQ(adder.get_sum(), 0);
    EXPECT_EQ(adder.get_carry(), 1);
}

TEST_F(FourBitAdderTest, RandomValues) {
    adder.set_inputs(7, 9);  // 7 (0111) + 9 (1001) = 16 (0001 0000)
    EXPECT_EQ(adder.get_sum(), 0);
    EXPECT_EQ(adder.get_carry(), 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}