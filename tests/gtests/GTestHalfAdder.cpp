
#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"

class HalfAdderTest : public ::testing::Test {
protected:
    HalfAdder halfAdder;
};

TEST_F(HalfAdderTest, ZeroPlusZero) {
    halfAdder.set_inputs(0, 0);
    EXPECT_EQ(halfAdder.get_sum(), 0);
    EXPECT_EQ(halfAdder.get_carry(), 0);
}

TEST_F(HalfAdderTest, ZeroPlusOne) {
    halfAdder.set_inputs(0, 1);
    EXPECT_EQ(halfAdder.get_sum(), 1);
    EXPECT_EQ(halfAdder.get_carry(), 0);
}

TEST_F(HalfAdderTest, OnePlusZero) {
    halfAdder.set_inputs(1, 0);
    EXPECT_EQ(halfAdder.get_sum(), 1);
    EXPECT_EQ(halfAdder.get_carry(), 0);
}

TEST_F(HalfAdderTest, OnePlusOne) {
    halfAdder.set_inputs(1, 1);
    EXPECT_EQ(halfAdder.get_sum(), 0);
    EXPECT_EQ(halfAdder.get_carry(), 1);
}

TEST_F(HalfAdderTest, MultipleInputs) {
    unsigned short int inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    unsigned short int expected_sums[4] = {0, 1, 1, 0};
    unsigned short int expected_carries[4] = {0, 0, 0, 1};

    for (int i = 0; i < 4; i++) {
        halfAdder.set_inputs(inputs[i][0], inputs[i][1]);
        EXPECT_EQ(halfAdder.get_sum(), expected_sums[i]) << "Failure for inputs: " << inputs[i][0] << ", " << inputs[i][1];
        EXPECT_EQ(halfAdder.get_carry(), expected_carries[i]) << "Failure for inputs: " << inputs[i][0] << ", " << inputs[i][1];
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}