#ifndef FibonacciBenchmark_H__
#define FibonacciBenchmark_H__

namespace benchmark
{
  class State;
}

void FibonacciRecursive(benchmark::State& state);
void FibonacciMemonized(benchmark::State& state);
void FibonacciDP(benchmark::State& state);
void FibonacciDPOptimized(benchmark::State& state);

#endif  // !FibonacciBenchmark_H__
