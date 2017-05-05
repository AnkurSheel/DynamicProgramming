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

    int minCost = insertCost;
    if (deleteCost < minCost)
    {
      minCost = deleteCost;
    }

    if (replaceCost < minCost)
    {
      minCost = replaceCost;
    }
    return 1 + minCost;
  }
  return -1;
}

//  *******************************************************************************************************************
string cEditDistance::Memonized(const string& first, const string& second)
{
  int length1 = first.length();
  int length2 = second.length();

  m_results.Init(length1 + 1, length2 + 1);
  m_Operations.Init(length1, length2);
  int operations = Memonized(first, second, 0, 0);
  return GetSteps(first, second, operations);
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
      m_Operations.SetElement(index1, index2, 0);
    }
    else
    {
      int insertCost = Memonized(first, second, index1, index2 + 1);
      int deleteCost = Memonized(first, second, index1 + 1, index2);
      int replaceCost = Memonized(first, second, index1 + 1, index2 + 1);

      int minCost = insertCost;
      m_Operations.SetElement(index1, index2, 1);

      if (deleteCost < minCost)
      {
        minCost = deleteCost;
        m_Operations.SetElement(index1, index2, 2);
      }

      if (replaceCost < minCost)
      {
        minCost = replaceCost;
        m_Operations.SetElement(index1, index2, 3);
      }

      m_results.SetElement(index1, index2, 1 + minCost);
    }
  }
  return m_results.GetElement(index1, index2);
}

//  *******************************************************************************************************************
string cEditDistance::DP(const std::string& first, const std::string& second)
{
  int length1 = first.length();
  int length2 = second.length();

  m_results.Init(length1 + 1, length2 + 1);

  for (int index1 = length1; index1 >= 0; index1--)
  {
    for (int index2 = length2; index2 >= 0; index2--)
    {
      if (index1 == length1)
      {
        m_results.SetElement(index1, index2, length2 - index2);
      }
      else if (index2 == length2)
      {
        m_results.SetElement(index1, index2, length1 - index1);
      }
      else if (first[index1] == second[index2])
      {
        m_results.SetElement(index1, index2, m_results.GetElement(index1 + 1, index2 + 1));
        m_Operations.SetElement(index1, index2, 0);
      }
      else
      {
        int insertCost = m_results.GetElement(index1, index2 + 1);
        int deleteCost = m_results.GetElement(index1 + 1, index2);
        int replaceCost = m_results.GetElement(index1 + 1, index2 + 1);

        int minCost = insertCost;
        m_Operations.SetElement(index1, index2, 1);

        if (deleteCost < minCost)
        {
          minCost = deleteCost;
          m_Operations.SetElement(index1, index2, 2);
        }

        if (replaceCost < minCost)
        {
          minCost = replaceCost;
          m_Operations.SetElement(index1, index2, 3);
        }

        m_results.SetElement(index1, index2, 1 + minCost);
      }
    }
  }

  int operations = m_results.GetElement(0, 0);
  return GetSteps(first, second, operations);
}

//  *******************************************************************************************************************
string cEditDistance::GetSteps(const std::string& first, const std::string& second, int numberOfOperations)
{
  int index1 = 0;
  int index2 = 0;
  stringstream steps;
  stringstream currentString;

  steps << "Number Of Operations : " << numberOfOperations << endl;

  if (numberOfOperations == 0)
  {
    return steps.str();
  }

  steps << "Starting String : " << first << endl;

  while (index1 < first.length() && index2 < second.length())
  {
    if (m_Operations.GetElement(index1, index2) == 0)  // match
    {
      currentString << first[index1];
      index1 = index1 + 1;
      index2 = index2 + 1;
    }
    else if (m_Operations.GetElement(index1, index2) == 1)  // insert
    {
      steps << "Insert character " << second[index2] << " : Current String " << currentString.str();
      currentString << second[index2];
      steps << " : Updated String " << currentString.str() << endl;
      index2 = index2 + 1;
    }
    else if (m_Operations.GetElement(index1, index2) == 2)  // delete
    {
      currentString << first[index1];
      steps << "Delete character " << first[index1] << " : Current String " << currentString.str();
      currentString.seekp(-1, ios_base::end);
      currentString << " ";
      steps << " : Updated String " << currentString.str() << endl;
      currentString.seekp(-1, ios_base::end);
      index1 = index1 + 1;
    }
    else if (m_Operations.GetElement(index1, index2) == 3)  // replace
    {
      steps << "Replace character " << first[index1] << " with character " << second[index2] << " : Current String ";
      currentString << first[index1];
      steps << currentString.str();
      currentString.seekp(-1, ios_base::end);
      currentString << second[index2];
      steps << " : Updated String " << currentString.str() << endl;
      index1 = index1 + 1;
      index2 = index2 + 1;
    }
  }
  if (second.length() - index2 > 0)
  {
    steps << "Current String \"" << currentString.str() << "\" : Insert remaining " << second.length() - index2
          << " characters from the second string at position " << index2 << endl;
  }
  if (first.length() - index1 > 0)
  {
    if (index1 == 0)
    {
      currentString << first;
    }
    steps << "Current String \"" << currentString.str() << "\" : Delete remaining " << first.length() - index1
          << " characters from position " << index1 << endl;
  }
  steps << "Final String : " << second << endl;
  return steps.str();
}