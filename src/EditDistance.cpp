#include "EditDistance.h"
#include "Includes.h"

using namespace std;
using namespace Common;

//  *******************************************************************************************************************
cEditDistance::cEditDistance()
{
}

//  *******************************************************************************************************************
cEditDistance::~cEditDistance()
{
}

//  *******************************************************************************************************************
int cEditDistance::Recursive(const string& first, const string& second)
{
  return Recursive(first, second, 0, 0);
}

//  *******************************************************************************************************************
int cEditDistance::Recursive(const string& first, const string& second, int index1, int index2)
{
  int length1 = first.length() - index1;
  int length2 = second.length() - index2;

  if (length1 == 0)
  {
    return length2;
  }

  if (length2 == 0)
  {
    return length1;
  }

  if (first[index1] == second[index2])
  {
    return Recursive(first, second, index1 + 1, index2 + 1);
  }
  else
  {
    int insertCost = Recursive(first, second, index1, index2 + 1);
    int deleteCost = Recursive(first, second, index1 + 1, index2);
    int replaceCost = Recursive(first, second, index1 + 1, index2 + 1);
    return 1 + min(insertCost, deleteCost, replaceCost);
  }
  return -1;
}

//  *******************************************************************************************************************
int cEditDistance::Memonized(const string& first, const string& second)
{
  int length1 = first.length();
  int length2 = second.length();

  m_results.Init(length1 + 1, length2 + 1);

  return Memonized(first, second, 0, 0);
}

//  *******************************************************************************************************************
int cEditDistance::Memonized(const string& first, const string& second, int index1, int index2)
{
  if (m_results.GetElement(index1, index2) == -1)
  {
    int length1 = first.length() - index1;
    int length2 = second.length() - index2;

    if (length1 == 0)
    {
      m_results.SetElement(index1, index2, length2);
    }
    else if (length2 == 0)
    {
      m_results.SetElement(index1, index2, length1);
    }
    else if (first[index1] == second[index2])
    {
      m_results.SetElement(index1, index2, Memonized(first, second, index1 + 1, index2 + 1));
    }
    else
    {
      int insertCost = Memonized(first, second, index1, index2 + 1);
      int deleteCost = Memonized(first, second, index1 + 1, index2);
      int replaceCost = Memonized(first, second, index1 + 1, index2 + 1);
      m_results.SetElement(index1, index2, 1 + min(insertCost, deleteCost, replaceCost));
    }
  }
  return m_results.GetElement(index1, index2);
}

//  *******************************************************************************************************************
int cEditDistance::DP(const std::string& first, const std::string& second)
{
  int length1 = first.length();
  int length2 = second.length();

  m_results.Init(length1 + 1, length2 + 1);

  for (int i = length1; i >= 0; i--)
  {
    for (int j = length2; j >= 0; j--)
    {
      if (i == length1)
      {
        m_results.SetElement(i, j, length2 - j);
      }
      else if (j == length2)
      {
        m_results.SetElement(i, j, length1 - i);
      }
      else if (first[i] == second[j])
      {
        m_results.SetElement(i, j, m_results.GetElement(i + 1, j + 1));
      }
      else
      {
        int insertCost = m_results.GetElement(i, j + 1);
        int deleteCost = m_results.GetElement(i + 1, j);
        int replaceCost = m_results.GetElement(i + 1, j + 1);
        m_results.SetElement(i, j, 1 + min(insertCost, deleteCost, replaceCost));
      }
    }
  }

  return m_results.GetElement(0, 0);
}

//  *******************************************************************************************************************
int cEditDistance::min(int x, int y, int z)
{
  return std::min<int>(std::min<int>(x, y), z);
}
