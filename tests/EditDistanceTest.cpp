#include <fstream>
#include "..\src\EditDistance.h"
#include "..\src\Includes.h"
#include "gtest\gtest.h"

using namespace testing;
using namespace std;

namespace Tests
{
  class EditDistance : public Test
  {
    virtual void SetUp() override { }

    virtual void TearDown() override { }

  protected:
    cEditDistance m_EditDistance;
    ifstream resultFile;
  };

  TEST_F(EditDistance, NoChange)
  {
    EXPECT_EQ(0, m_EditDistance.Recursive("", ""));
    EXPECT_EQ(0, m_EditDistance.Recursive("ABC", "ABC"));

    resultFile.open("./tests/DataFiles/EditDistance/NoChange.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized("", "").data());
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized("ABC", "ABC").data());

    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP("", "").data());
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized("ABC", "ABC").data());
  }

  TEST_F(EditDistance, FirstStringEmpty)
  {
    EXPECT_EQ(3, m_EditDistance.Recursive("", "ABC"));

    resultFile.open("./tests/DataFiles/EditDistance/FirstStringEmpty.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized("", "ABC").data());
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP("", "ABC").data());
  }

  TEST_F(EditDistance, SecondStringEmpty)
  {
    EXPECT_EQ(3, m_EditDistance.Recursive("ABC", ""));

    resultFile.open("./tests/DataFiles/EditDistance/SecondStringEmpty.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized("ABC", "").data());
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP("ABC", "").data());
  }


  TEST_F(EditDistance, Case1)
  {
    string string1 = "geek";
    string string2 = "gesek";

    resultFile.open("./tests/DataFiles/EditDistance/Case1.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(1, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case2)
  {
    string string1 = "cat";
    string string2 = "cut";

    resultFile.open("./tests/DataFiles/EditDistance/Case2.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(1, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case3)
  {
    string string1 = "sunday";
    string string2 = "saturday";

    resultFile.open("./tests/DataFiles/EditDistance/Case3.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(3, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case4)
  {
    string string1 = "cat";
    string string2 = "cars";

    resultFile.open("./tests/DataFiles/EditDistance/Case4.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(2, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case5)
  {
    string string1 = "AC";
    string string2 = "ABCD";

    resultFile.open("./tests/DataFiles/EditDistance/Case5.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(2, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

  TEST_F(EditDistance, Case6)
  {
    string string1 = "ABCD";
    string string2 = "AC";

    resultFile.open("./tests/DataFiles/EditDistance/Case6.txt");
    stringstream expectedStream;
    expectedStream << resultFile.rdbuf();

    EXPECT_EQ(2, m_EditDistance.Recursive(string1.data(), string2.data())) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.Memonized(string1.data(), string2.data()).data()) << string1 << " : " << string2;
    EXPECT_STREQ(expectedStream.str().data(), m_EditDistance.DP(string1.data(), string2.data()).data()) << string1 << " : " << string2;
  }

}
