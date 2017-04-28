#ifndef Fibonacci_H__
#define Fibonacci_H__

#include <map>

class cFibonacci
{
public:
  long Recursive(long n);
  long Memonized(long n);
  long DP(long n);
  long DPOptimized(long n);

private:
  long Memonized(long n, std::map<long, long>& computedValues);
};

#endif  // Fibonacci_H__
