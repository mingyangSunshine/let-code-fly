#include "solution_test.h"
#include <iostream>

SolutionTest::SolutionTest()
{}

TEST_F(SolutionTest, TestCase1)
{
    EXPECT_EQ(solution_.intToRoman(3), "III");
    EXPECT_EQ(solution_.intToRoman(4), "IV");
}