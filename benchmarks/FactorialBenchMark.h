#ifndef FactorialBenchMark_H__
#define FactorialBenchMark_H__

namespace benchmark
{
  class State;
}

void FactorialRecursive(benchmark::State& state);
void FactorialDP(benchmark::State& state);
void FactorialDPOptimized(benchmark::State& state);

#endif  // FactorialBenchMark_H__
