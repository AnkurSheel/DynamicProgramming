#include "Custom2DArray.h"
#include "Includes.h"

using namespace std;

Common::cCustom2DArray::cCustom2DArray()
  : m_results(nullptr)
  , m_rowLength(0)
  , m_size(0)
{
}

Common::cCustom2DArray::~cCustom2DArray()
{
  delete[] m_results;
  m_results = nullptr;
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::InitResultsArray(int length1, int length2)
{
  int newSize = (length1 + 1) * (length2 + 1);
  if (m_rowLength != length1 && m_size != newSize)
  {
    if (m_results != nullptr)
    {
      delete[] m_results;
      m_results = nullptr;
    }

    m_rowLength = length1;
    m_size = newSize;

    m_results = new int[m_size];
    memset(m_results, -1, m_size * sizeof(int));
  }
  Reset();
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::Reset()
{
  if (m_results != nullptr)
  {
    memset(m_results, -1, m_size * sizeof(int));
  }
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::PrintArray(const string& first, const string& second)
{
  int width = 4;
  for (int i = 0; i < first.length(); i++)
  {
    cout << setw(width) << first[i];
  }
  int j = 0;
  for (int i = 0; i < m_size; i++)
  {
    if (i % (m_rowLength + 1) == 0)
    {
      cout << "\n";
      if (j < second.length())
      {
        cout << second[j];
        j++;
        width = 3;
      }
    }
    else
    {
      width = 4;
    }
    cout << setw(width) << m_results[i];
  }
  cout << "\n";
}
