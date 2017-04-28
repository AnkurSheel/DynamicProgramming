#include "..\src\Includes.h"
#include "..\src\LCS.h"
#include "gtest\gtest.h"

using namespace testing;
using namespace std;

namespace Tests
{
  class LCS : public Test
  {
    virtual void SetUp() override {}

    virtual void TearDown() override {}

  protected:
    cLCS m_lcs;
  };

  TEST_F(LCS, BaseCases)
  {
    EXPECT_EQ(0, m_lcs.Recursive("", ""));
    EXPECT_EQ(0, m_lcs.Recursive("A", ""));
    EXPECT_EQ(0, m_lcs.Recursive("", "A"));

    string result = "";

    EXPECT_STREQ(result.data(), m_lcs.Memonized("", "").data());
    EXPECT_STREQ(result.data(), m_lcs.Memonized("A", result.data()).data());
    EXPECT_STREQ(result.data(), m_lcs.Memonized("", "A").data());

    EXPECT_STREQ(result.data(), m_lcs.DP("", "").data());
    EXPECT_STREQ(result.data(), m_lcs.DP("A", "").data());
    EXPECT_STREQ(result.data(), m_lcs.DP("", "A").data());
  }

  TEST_F(LCS, Case1)
  {
    string string1 = "ABCDGH";
    string string2 = "AEDFHR";
    string result = "ADH";

    EXPECT_EQ(3, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }

  TEST_F(LCS, Case2)
  {
    string string1 = "AGGTAB";
    string string2 = "GXTXAYB";
    string result = "GTAB";

    EXPECT_EQ(4, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }

  TEST_F(LCS, Case3)
  {
    string string1 = "1234";
    string string2 = "3412";
    string result = "34";

    EXPECT_EQ(2, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }

  TEST_F(LCS, Case4)
  {
    string string1 = "HUMAN";
    string string2 = "CHIMPANZEE";
    string result = "HMAN";

    EXPECT_EQ(4, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }

  TEST_F(LCS, Case5)
  {
    string string1 = "HELLO";
    string string2 = "WORLD";
    string result = "O";

    EXPECT_EQ(1, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }

  TEST_F(LCS, Case6)
  {
    string string1 = "nematode knowledge";
    string string2 = "empty bottle";
    string result = "emt ole";

    EXPECT_EQ(7, m_lcs.Recursive(string1.data(), string2.data()));
    EXPECT_STREQ(result.data(), m_lcs.Memonized(string1, string2).data());
    EXPECT_STREQ(result.data(), m_lcs.DP(string1, string2).data());
  }
}
