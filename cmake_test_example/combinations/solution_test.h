#ifndef SOLUTION_TEST_H
#define SOLUTION_TEST_H

#include <gtest/gtest.h>
#include "solution.hpp"

class SolutionTest: public ::testing::Test
{
    public:
        SolutionTest();
        
    protected:
        Solution solution_;
};

#endif