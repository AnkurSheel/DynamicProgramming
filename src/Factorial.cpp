#include "Factorial.h"
#include "Includes.h"

//  *******************************************************************************************************************
long Factorial(long n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * Factorial(n - 1) % MOD;
}

//  *******************************************************************************************************************
long FactorialDP(long n)
{
  long* results = new long[n + 1];
  results[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    results[i] = results[i - 1] * i % MOD;
  }
  long value = results[n];
  delete[] results;
  return value;
}

//  *******************************************************************************************************************
long FactorialDPOptimized(long n)
{
  long n1 = 1;
  long current = 1;
  for (int i = 1; i <= n; i++)
  {
    current = i * n1 % MOD;
    n1 = current;
  }
  return current;
}
