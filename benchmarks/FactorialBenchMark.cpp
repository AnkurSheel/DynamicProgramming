#include <sstream>
#include "..\src\Factorial.h"
#include "FactorialBenchmark.h"
#include "benchmark/benchmark_api.h"

static void SetState(long factorial, benchmark::State& state)
{
  std::stringstream ss;
  ss << "Result : " << state.range(0) << " : " << factorial;
  state.SetLabel(ss.str());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range_x());
}

void FactorialRecursive(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = Factorial(state.range_x()));
  }
  SetState(fib, state);
}

void FactorialDP(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = FactorialDP(state.range_x()));
  }
  SetState(fib, state);
}

void FactorialDPOptimized(benchmark::State& state)
{
  long fib = 0;
  while (state.KeepRunning())
  {
    benchmark::DoNotOptimize(fib = FactorialDPOptimized(state.range_x()));
  }
  SetState(fib, state);
}
