#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"

class FullAdderTest : public ::testing::Test {
protected:
    FullAdder fullAdder;
};

TEST_F(FullAdderTest, ZeroZeroZero) {
    fullAdder.set_inputs(0, 0, 0);
    EXPECT_EQ(fullAdder.get_sum(), 0);
    EXPECT_EQ(fullAdder.get_carry(), 0);
}

TEST_F(FullAdderTest, ZeroZeroOne) {
    fullAdder.set_inputs(0, 0, 1);
    EXPECT_EQ(fullAdder.get_sum(), 1);
    EXPECT_EQ(fullAdder.get_carry(), 0);
}

TEST_F(FullAdderTest, ZeroOneZero) {
    fullAdder.set_inputs(0, 1, 0);
    EXPECT_EQ(fullAdder.get_sum(), 1);
    EXPECT_EQ(fullAdder.get_carry(), 0);
}

TEST_F(FullAdderTest, ZeroOneOne) {
    fullAdder.set_inputs(0, 1, 1);
    EXPECT_EQ(fullAdder.get_sum(), 0);
    EXPECT_EQ(fullAdder.get_carry(), 1);
}

TEST_F(FullAdderTest, OneZeroZero) {
    fullAdder.set_inputs(1, 0, 0);
    EXPECT_EQ(fullAdder.get_sum(), 1);
    EXPECT_EQ(fullAdder.get_carry(), 0);
}

TEST_F(FullAdderTest, OneZeroOne) {
    fullAdder.set_inputs(1, 0, 1);
    EXPECT_EQ(fullAdder.get_sum(), 0);
    EXPECT_EQ(fullAdder.get_carry(), 1);
}

TEST_F(FullAdderTest, OneOneZero) {
    fullAdder.set_inputs(1, 1, 0);
    EXPECT_EQ(fullAdder.get_sum(), 0);
    EXPECT_EQ(fullAdder.get_carry(), 1);
}

TEST_F(FullAdderTest, OneOneOne) {
    fullAdder.set_inputs(1, 1, 1);
    EXPECT_EQ(fullAdder.get_sum(), 1);
    EXPECT_EQ(fullAdder.get_carry(), 1);
}

TEST_F(FullAdderTest, AllCombinations) {
    unsigned short int inputs[8][3] = {
        {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
        {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}
    };
    unsigned short int expected_sums[8] = {0, 1, 1, 0, 1, 0, 0, 1};
    unsigned short int expected_carries[8] = {0, 0, 0, 1, 0, 1, 1, 1};

    for (int i = 0; i < 8; i++) {
        fullAdder.set_inputs(inputs[i][0], inputs[i][1], inputs[i][2]);
        EXPECT_EQ(fullAdder.get_sum(), expected_sums[i])
                << "Failure for inputs: " << inputs[i][0] << ", " << inputs[i][1] << ", " << inputs[i][2];
        EXPECT_EQ(fullAdder.get_carry(), expected_carries[i])
                << "Failure for inputs: " << inputs[i][0] << ", " << inputs[i][1] << ", " << inputs[i][2];
    }
}