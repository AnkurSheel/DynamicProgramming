#include <sstream>
#include "..\src\Factorial.h"
#include "benchmark/benchmark_api.h"

using namespace benchmark;

namespace Benchmarks
{
  class Factorial : public Fixture
  {
  public:
    void SetUp(const State& st) {}
    void TearDown(const State& state) {}
    void SetState(long factorial, State& state)
    {
      std::stringstream ss;
      ss << "Result : " << state.range(0) << " : " << factorial;
      state.SetLabel(ss.str());
      state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
      state.SetItemsProcessed(state.iterations() * state.range(0));
      state.SetComplexityN(state.range(0));
    }

  protected:
    cFactorial m_factorial;
  };

  BENCHMARK_DEFINE_F(Factorial, Recursive)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_factorial.Recursive(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_DEFINE_F(Factorial, DP)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_factorial.DP(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_DEFINE_F(Factorial, DPOptimized)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_factorial.DPOptimized(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_REGISTER_F(Factorial, Recursive)->Arg(1000)->Arg(2000)->Unit(kNanosecond)->Complexity();

  BENCHMARK_REGISTER_F(Factorial, DP)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(Factorial, DPOptimized)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();
}
