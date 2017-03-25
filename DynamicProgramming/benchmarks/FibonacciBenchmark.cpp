#ifdef RUN_BENCHMARKS
#include "FibonacciBenchmark.h"
#include <sstream>
#include "..\src\Fibonacci.h"
#include "benchmark/benchmark_api.h"

void SetState(long fib, benchmark::State& state)
{
  std::stringstream ss;
  ss << "Result : " << state.range(0) << " : " << fib;
  state.SetLabel(ss.str());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range_x());
}
void FibonacciRecursive(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = Fibonacci(state.range_x()));
  }
  SetState(fib, state);
}

void FibonacciMemonized(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = FibonacciMemonized(state.range_x()));
  }
  SetState(fib, state);
}

void FibonacciDP(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = FibonacciDP(state.range_x()));
  }
  SetState(fib, state);
}

void FibonacciDPOptimized(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = FibonacciDPOptimized(state.range_x()));
  }
  SetState(fib, state);
}
#endif