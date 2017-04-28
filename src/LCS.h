#ifndef LCS_H__
#define LCS_H__

#include <string>

class cLCS
{
public:
  cLCS();
  ~cLCS();
  int Recursive(const char* const first, const char* const second);
  std::string Memonized(const std::string& first, const std::string& second);
  std::string DP(const std::string& first, const std::string& second);

private:
  int GetIndex(int i, int j) { return i + ((m_rowLength + 1) * j); }
  int Memonized(const char* const first, const char* const second, int i, int j);
  void InitResultsArray();
  void Reset();
  void PrintArray(const std::string& first, const std::string& second);
  std::string GetText(const std::string& first, const std::string& second);

private:
  int* m_results;
  int m_rowLength;
  int m_size;
};

#endif  // LCS_H__
