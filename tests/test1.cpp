#include <iostream>
#include "gtest/gtest.h"
#include "functions.h"

TEST(mathExpectationTwoParameters, outOfBoundsGap) {
    const std::vector<ulong> inputData = {343, 222, 2335};
    auto result = mathExpectation(inputData, 3);
    EXPECT_EQ(1450, result);
}
