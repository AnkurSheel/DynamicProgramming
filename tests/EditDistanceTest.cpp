#include "..\src\EditDistance.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

using namespace testing;
using namespace std;

namespace Tests
{
  class EditDistance : public Test
  {
    virtual void SetUp() override {}

    virtual void TearDown() override {}

  protected:
    cEditDistance m_EditDistance;
  };

  TEST_F(EditDistance, NoChange)
  {
    EXPECT_EQ(0, m_EditDistance.Recursive("", ""));
    EXPECT_EQ(0, m_EditDistance.Recursive("ABC", "ABC"));

    EXPECT_EQ(0, m_EditDistance.Memonized("", ""));
    EXPECT_EQ(0, m_EditDistance.Memonized("ABC", "ABC"));

    EXPECT_EQ(0, m_EditDistance.DP("", ""));
    EXPECT_EQ(0, m_EditDistance.DP("ABC", "ABC"));
  }

  TEST_F(EditDistance, EmptyString)
  {
    EXPECT_EQ(3, m_EditDistance.Recursive("", "ABC"));
    EXPECT_EQ(3, m_EditDistance.Recursive("ABC", ""));

    EXPECT_EQ(3, m_EditDistance.Memonized("", "ABC"));
    EXPECT_EQ(3, m_EditDistance.Memonized("ABC", ""));

    EXPECT_EQ(3, m_EditDistance.DP("", "ABC"));
    EXPECT_EQ(3, m_EditDistance.DP("ABC", ""));
  }

  TEST_F(EditDistance, Case1)
  {
    string string1 = "geek";
    string string2 = "gesek";

    EXPECT_EQ(1, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(1, m_EditDistance.Memonized(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(1, m_EditDistance.DP(string1.data(), string2.data())) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case2)
  {
    string string1 = "cat";
    string string2 = "cut";

    EXPECT_EQ(1, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(1, m_EditDistance.Memonized(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(1, m_EditDistance.DP(string1.data(), string2.data())) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case3)
  {
    string string1 = "sunday";
    string string2 = "saturday";

    EXPECT_EQ(3, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(3, m_EditDistance.Memonized(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(3, m_EditDistance.DP(string1.data(), string2.data())) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case4)
  {
    string string1 = "cat";
    string string2 = "cars";

    EXPECT_EQ(2, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(2, m_EditDistance.Memonized(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_EQ(2, m_EditDistance.DP(string1.data(), string2.data())) << string1 << " : " << string2;
  }
}
