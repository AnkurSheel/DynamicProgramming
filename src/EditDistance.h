#ifndef EditDistance_H__
#define EditDistance_H__

#include <string>
#include "Custom2DArray.h"

class cEditDistance
{
public:
  cEditDistance();
  ~cEditDistance();
  int Recursive(const std::string& first, const std::string& second);
  std::string Memonized(const std::string& first, const std::string& second);
  std::string DP(const std::string& first, const std::string& second);

private:
  int Recursive(const std::string& first, const std::string& second, int index1, int index2);
  int Memonized(const std::string& first, const std::string& second, int index1, int index2);
  std::string GetSteps(const std::string& first, const std::string& second, int numberOfOperations);

private:
  Common::cCustom2DArray m_results;
  Common::cCustom2DArray m_Operations;
};

#endif  // EditDistance_H__
