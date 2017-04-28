#include "..\src\Factorial.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

using namespace testing;

namespace Tests
{
  class Factorial : public Test
  {
    virtual void SetUp() override {}

    virtual void TearDown() override {}

  protected:
    cFactorial m_factorial;
  };

  TEST_F(Factorial, BaseCases)
  {
    EXPECT_EQ(1, m_factorial.Recursive(0));

    EXPECT_EQ(1, m_factorial.DP(0));

    EXPECT_EQ(1, m_factorial.DPOptimized(0));
  }

  TEST_F(Factorial, 1)
  {
    EXPECT_EQ(1, m_factorial.Recursive(1));

    EXPECT_EQ(1, m_factorial.DP(1));

    EXPECT_EQ(1, m_factorial.DPOptimized(1));
  }

  TEST_F(Factorial, 6)
  {
    EXPECT_EQ(720, m_factorial.Recursive(6));

    EXPECT_EQ(720, m_factorial.DP(6));

    EXPECT_EQ(720, m_factorial.DPOptimized(6));
  }
}