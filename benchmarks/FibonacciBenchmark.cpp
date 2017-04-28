#include <sstream>
#include "..\src\Fibonacci.h"
#include "benchmark/benchmark_api.h"

using namespace benchmark;

namespace Benchmarks
{
  class Fibonacci : public Fixture
  {
  public:
    void SetUp(const State& st) {}
    void TearDown(const State& state) {}
    void SetState(long fib, State& state)
    {
      std::stringstream ss;
      ss << "Result : " << state.range(0) << " : " << fib;
      state.SetLabel(ss.str());
      state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(int));
      state.SetItemsProcessed(state.iterations() * state.range(0));
      state.SetComplexityN(state.range(0));
    }

  protected:
    cFibonacci m_fibonnaci;
  };

  BENCHMARK_DEFINE_F(Fibonacci, Recursive)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_fibonnaci.Recursive(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_DEFINE_F(Fibonacci, Memonized)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_fibonnaci.Memonized(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_DEFINE_F(Fibonacci, DP)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_fibonnaci.DP(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_DEFINE_F(Fibonacci, DPOptimized)(State& state)
  {
    long fib = 0;
    while (state.KeepRunning())
    {
      DoNotOptimize(fib = m_fibonnaci.DPOptimized(state.range(0)));
    }
    SetState(fib, state);
  }

  BENCHMARK_REGISTER_F(Fibonacci, Recursive)->Arg(10)->Arg(20)->Arg(30)->Unit(kNanosecond)->Complexity();

  BENCHMARK_REGISTER_F(Fibonacci, Memonized)->DenseRange(100, 1000, 200)->Unit(kNanosecond)->Complexity();

  BENCHMARK_REGISTER_F(Fibonacci, DP)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(Fibonacci, DPOptimized)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();
}