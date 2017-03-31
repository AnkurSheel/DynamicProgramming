#include "..\src\Fibonacci.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

TEST(Fibonacci, BaseCases)
{
  EXPECT_EQ(0, Fibonacci(0));
  EXPECT_EQ(1, Fibonacci(1));

  EXPECT_EQ(0, FibonacciMemonized(0));
  EXPECT_EQ(1, FibonacciMemonized(1));

  EXPECT_EQ(0, FibonacciDP(0));
  EXPECT_EQ(1, FibonacciDP(1));

  EXPECT_EQ(0, FibonacciDPOptimized(0));
  EXPECT_EQ(1, FibonacciDPOptimized(1));
}

TEST(Fibonacci, 2)
{
  EXPECT_EQ(1, Fibonacci(2));

  EXPECT_EQ(1, FibonacciMemonized(2));

  EXPECT_EQ(1, FibonacciDP(2));

  EXPECT_EQ(1, FibonacciDPOptimized(2));
}

TEST(Fibonacci, 6)
{
  EXPECT_EQ(8, Fibonacci(6));

  EXPECT_EQ(8, FibonacciMemonized(6));

  EXPECT_EQ(8, FibonacciDP(6));

  EXPECT_EQ(8, FibonacciDPOptimized(6));
}
