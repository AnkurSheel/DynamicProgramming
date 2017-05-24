#include "LCS.h"
#include "Includes.h"

using namespace std;

//  *******************************************************************************************************************
cLCS::cLCS()
{
}

//  *******************************************************************************************************************
cLCS::~cLCS()
{
}

//  *******************************************************************************************************************
int cLCS::Recursive(const char* const first, const char* const second)
{
  if (*first == '\0' || *second == '\0')
  {
    return 0;
  }
  if (*first == *second)
  {
    return 1 + Recursive(first + 1, second + 1);
  }
  return max(Recursive(first + 1, second), Recursive(first, second + 1));
}

//  *******************************************************************************************************************
string cLCS::Memonized(const string& first, const string& second)
{
  int length1 = static_cast<int>(first.length());
  int length2 = static_cast<int>(second.length());

  if (length1 == 0 || length2 == 0)
  {
    return "";
  }
  m_results.Init(length1 + 1, length2 + 1);
  Memonized(first.data(), second.data(), 0, 0);
  return GetText(first, second);
}

//  *******************************************************************************************************************
int cLCS::Memonized(const char* const first, const char* const second, int i, int j)
{
  if (m_results.GetElement(i, j) == -1)
  {
    if (first[i] == '\0' || second[j] == '\0')
    {
      m_results.SetElement(i, j, 0);
    }
    else if (first[i] == second[j])
    {
      m_results.SetElement(i, j, 1 + Memonized(first, second, i + 1, j + 1));
    }
    else
    {
      int val1 = Memonized(first, second, i + 1, j);
      int val2 = Memonized(first, second, i, j + 1);
      m_results.SetElement(i, j, max(val1, val2));
    }
  }
  return m_results.GetElement(i, j);
}

//  *******************************************************************************************************************
string cLCS::DP(const std::string& first, const std::string& second)
{
  int length1 = static_cast<int>(first.length());
  int length2 = static_cast<int>(second.length());

  if (length1 == 0 || length2 == 0)
  {
    return "";
  }
  m_results.Init(length1 + 1, length2 + 1);

  for (int i = length1; i >= 0; i--)
  {
    for (int j = length2; j >= 0; j--)
    {
      if (first[i] == '\0' || second[j] == '\0')
      {
        m_results.SetElement(i, j, 0);
      }
      else if (first[i] == second[j])
      {
        m_results.SetElement(i, j, 1 + m_results.GetElement(i + 1, j + 1));
      }
      else
      {
        m_results.SetElement(i, j, max(m_results.GetElement(i + 1, j), m_results.GetElement(i, j + 1)));
      }
    }
  }
  return GetText(first, second);
}

//  *******************************************************************************************************************
string cLCS::GetText(const string& first, const string& second)
{
  if (m_results.GetElement(0, 0) == 0)
  {
    return "";
  }
  int i = 0;
  int j = 0;
  stringstream ss("");
  while (i < first.length() && j < second.length())
  {
    if (first[i] == second[j])
    {
      ss << first[i];
      i++;
      j++;
    }
    else if (m_results.GetElement(i + 1, j) >= m_results.GetElement(i, j + 1))
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  return ss.str();
}
