#ifndef LCS_H__
#define LCS_H__

#include <string>
#include "Custom2DArray.h"

class cLCS
{
public:
  cLCS();
  ~cLCS();
  int Recursive(const char* const first, const char* const second);
  std::string Memonized(const std::string& first, const std::string& second);
  std::string DP(const std::string& first, const std::string& second);

private:
  int Memonized(const char* const first, const char* const second, int i, int j);
  std::string GetText(const std::string& first, const std::string& second);

private:
  Common::cCustom2DArray m_results;
};

#endif  // LCS_H__
