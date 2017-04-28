#include "..\src\Fibonacci.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

using namespace testing;

namespace Tests
{
  class Fibonacci : public Test
  {
    virtual void SetUp() override {}

    virtual void TearDown() override {}

  protected:
    cFibonacci m_fibonnaci;
  };

  TEST_F(Fibonacci, BaseCases)
  {
    EXPECT_EQ(0, m_fibonnaci.Recursive(0));
    EXPECT_EQ(1, m_fibonnaci.Recursive(1));

    EXPECT_EQ(0, m_fibonnaci.Memonized(0));
    EXPECT_EQ(1, m_fibonnaci.Memonized(1));

    EXPECT_EQ(0, m_fibonnaci.DP(0));
    EXPECT_EQ(1, m_fibonnaci.DP(1));

    EXPECT_EQ(0, m_fibonnaci.DPOptimized(0));
    EXPECT_EQ(1, m_fibonnaci.DPOptimized(1));
  }

  TEST_F(Fibonacci, 2)
  {
    EXPECT_EQ(1, m_fibonnaci.Recursive(2));

    EXPECT_EQ(1, m_fibonnaci.Memonized(2));

    EXPECT_EQ(1, m_fibonnaci.DP(2));

    EXPECT_EQ(1, m_fibonnaci.DPOptimized(2));
  }

  TEST_F(Fibonacci, 6)
  {
    EXPECT_EQ(8, m_fibonnaci.Recursive(6));

    EXPECT_EQ(8, m_fibonnaci.Memonized(6));

    EXPECT_EQ(8, m_fibonnaci.DP(6));

    EXPECT_EQ(8, m_fibonnaci.DPOptimized(6));
  }
}