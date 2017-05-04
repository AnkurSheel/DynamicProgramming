#ifndef Custom2DArray_H__
#define Custom2DArray_H__

#include <string>

namespace Common
{
  class cCustom2DArray
  {
  public:
    cCustom2DArray();
    ~cCustom2DArray();

    int GetElement(int i, int j) const { return m_results[GetIndex(i, j)]; }
    void SetElement(int i, int j, int value) { m_results[GetIndex(i, j)] = value; }
    void InitResultsArray(int length1, int length2);
    void PrintArray(const std::string& first, const std::string& second);

  private:
    void Reset();
    int GetIndex(int i, int j) const { return i + ((m_rowLength + 1) * j); }

  private:
    int* m_results;
    int m_rowLength;
    int m_size;
  };
}
#endif  // Custom2DArray_H__
