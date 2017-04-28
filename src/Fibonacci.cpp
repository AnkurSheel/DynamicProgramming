#include "Fibonacci.h"
#include "Includes.h"

using namespace std;

//  *******************************************************************************************************************
long cFibonacci::Recursive(long n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return (Recursive(n - 2) + Recursive(n - 1)) % MOD;
}

//  *******************************************************************************************************************
long cFibonacci::Memonized(long n)
{
  std::map<long, long> computedValues;
  computedValues.insert(make_pair(0, 0));
  computedValues.insert(make_pair(1, 1));
  return Memonized(n, computedValues);
}

//  *******************************************************************************************************************
long cFibonacci::Memonized(long n, std::map<long, long>& computedValues)
{
  if (computedValues.find(n) != computedValues.end())
  {
    return computedValues[n];
  }
  long newValue = (Memonized(n - 1, computedValues) + Memonized(n - 2, computedValues)) % MOD;
  computedValues.insert(make_pair(n, newValue));
  return newValue;
}

//  *******************************************************************************************************************
long cFibonacci::DP(long n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  long* results = new long[n + 1];
  results[0] = 0;
  results[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    results[i] = (results[i - 1] + results[i - 2]) % MOD;
  }
  long value = results[n];
  delete[] results;
  return value;
}

//  *******************************************************************************************************************
long cFibonacci::DPOptimized(long n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  long n1 = 0;
  long n2 = 1;
  long current = 0;
  for (int i = 2; i <= n; i++)
  {
    current = (n1 + n2) % MOD;
    n1 = n2;
    n2 = current;
  }
  return current;
}
