#include "solution_test.h"
#include <iostream>

SolutionTest::SolutionTest()
{}

TEST_F(SolutionTest, TestCase1)
{
    vector<vector<int>> result = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    EXPECT_EQ(solution_.combine(4, 2), result);
}