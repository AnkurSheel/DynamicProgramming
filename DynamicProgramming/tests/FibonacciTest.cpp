#ifdef RUN_TESTS

#include "..\src\Fibonacci.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

TEST(Fibonacci, BaseCases)
{
  EXPECT_EQ(0, FibonacciDPOptimized(0));
  EXPECT_EQ(1, FibonacciDPOptimized(1));
}

TEST(Fibonacci, 2)
{
  EXPECT_EQ(1, FibonacciDPOptimized(2));
}

TEST(Fibonacci, 6)
{
  EXPECT_EQ(8, FibonacciDPOptimized(6));
}

TEST(Fibonacci, 100000)
{
  auto startTime = Clock::now();
  EXPECT_EQ(911435502, FibonacciDPOptimized(100000));
  auto endTime = Clock::now();
  auto difference = FpSeconds(endTime - startTime);
  ASSERT_LE(difference.count(), 0.005);
}
#endif // RUN_TESTS
