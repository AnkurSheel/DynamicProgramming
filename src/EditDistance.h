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
  int Memonized(const std::string& first, const std::string& second);
  int DP(const std::string& first, const std::string& second);

private:
  int Recursive(const std::string& first, const std::string& second, int index1, int index2);
  int Memonized(const std::string& first, const std::string& second, int index1, int index2);
  int min(int x, int y, int z);

private:
  Common::cCustom2DArray m_results;
};

#endif  // EditDistance_H__
