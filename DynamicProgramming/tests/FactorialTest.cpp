#ifdef RUN_TESTS

#include "..\src\Factorial.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

TEST(Factorial, BaseCases)
{
  EXPECT_EQ(1, Factorial(0));

  EXPECT_EQ(1, FactorialDP(0));

  EXPECT_EQ(1, FactorialDPOptimized(0));
}

TEST(Factorial, 1)
{
  EXPECT_EQ(1, Factorial(1));

  EXPECT_EQ(1, FactorialDP(1));

  EXPECT_EQ(1, FactorialDPOptimized(1));
}

TEST(Factorial, 6)
{
  EXPECT_EQ(720, Factorial(6));

  EXPECT_EQ(720, FactorialDP(6));

  EXPECT_EQ(720, FactorialDPOptimized(6));
}

#endif  // RUN_TESTS
