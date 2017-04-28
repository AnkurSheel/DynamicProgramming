#include "Factorial.h"
#include "Includes.h"

//  *******************************************************************************************************************
long cFactorial::Recursive(long n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * Recursive(n - 1) % MOD;
}

//  *******************************************************************************************************************
long cFactorial::DP(long n)
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
long cFactorial::DPOptimized(long n)
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
