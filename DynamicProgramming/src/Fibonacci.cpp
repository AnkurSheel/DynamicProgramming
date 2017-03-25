#include "Fibonacci.h"
#include "Includes.h"

using namespace std;

//  *******************************************************************************************************************
long FibonacciMemonized(long n, std::map<long, long>& computedValues)
{
  if (computedValues.find(n) != computedValues.end())
  {
    return computedValues[n];
  }
  computedValues.insert(make_pair(n - 1, FibonacciMemonized(n - 1, computedValues)));
  computedValues.insert(make_pair(n - 2, FibonacciMemonized(n - 2, computedValues)));
  long newValue = (computedValues[n - 1] + computedValues[n - 2]) % MOD;
  computedValues.insert(make_pair(n, newValue));
  return newValue;
}

//  *******************************************************************************************************************
long Fibonacci(long n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return Fibonacci(n - 2) + Fibonacci(n - 1);
}

//  *******************************************************************************************************************
long FibonacciMemonized(long n)
{
  std::map<long, long> computedValues;
  computedValues.insert(make_pair(0, 1));
  computedValues.insert(make_pair(1, 1));
  return FibonacciMemonized(n, computedValues);
}

//  *******************************************************************************************************************
long FibonacciDP(long n)
{
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
long FibonacciDPOptimized(long n)
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