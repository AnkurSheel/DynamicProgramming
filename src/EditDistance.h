#ifndef EditDistance_H__
#define EditDistance_H__

#include <string>

class cEditDistance
{
public:
  cEditDistance();
  ~cEditDistance();
  int Recursive(const std::string& first, const std::string& second);
  int Memonized(const std::string& first, const std::string& second);
  int DP(const std::string& first, const std::string& second);

private:
  int GetIndex(int i, int j) { return i + ((m_rowLength + 1) * j); }
  int Recursive(const std::string& first, const std::string& second, int index1, int index2);
  int Memonized(const std::string& first, const std::string& second, int index1, int index2);
  void InitResultsArray();
  void Reset();
  int min(int x, int y, int z);

private:
  int* m_results;
  int m_rowLength;
  int m_size;
};

#endif  // EditDistance_H__
