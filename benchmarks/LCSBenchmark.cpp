#include <sstream>
#include <string>
#include "..\src\LCS.h"
#include "benchmark/benchmark_api.h"

using namespace benchmark;
using namespace std;

namespace Benchmarks
{
  class LCS : public Fixture
  {
  public:
    void SetUp(const State& state)
    {
      int length = state.range(0);
      m_string1 = new char[length];
      m_string2 = new char[length];
      memset(m_string1, 'a', length - 1);
      *(m_string1 + length - 1) = '\0';
      memset(m_string2, 'b', length - 1);
      *(m_string2 + length - 1) = '\0';
    }

    void TearDown(const ::State& state) {}
    void SetState(string lcs, State& state)
    {
      stringstream ss;
      state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char) * 2);
      state.SetItemsProcessed(state.iterations() * state.range(0));
      state.SetComplexityN(state.range(0));
    }

  protected:
    cLCS m_lcs;
    char* m_string1;
    char* m_string2;
  };

  BENCHMARK_DEFINE_F(LCS, Recursive)(State& state)
  {
    int lcs;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(lcs = m_lcs.Recursive(m_string1, m_string2));
    }
    SetState("", state);
  }

  //  *******************************************************************************************************************
  BENCHMARK_DEFINE_F(LCS, Memonized)(State& state)
  {
    string lcs;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(lcs = m_lcs.Memonized(m_string1, m_string2));
    }
    SetState(lcs, state);
  }

  //  *******************************************************************************************************************
  BENCHMARK_DEFINE_F(LCS, DP)(State& state)
  {
    string lcs;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(lcs = m_lcs.DP(m_string1, m_string2));
    }
    SetState(lcs, state);
  }

  BENCHMARK_REGISTER_F(LCS, Recursive)->DenseRange(10, 14, 2)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(LCS, Memonized)->DenseRange(100, 1000, 200)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(LCS, DP)->DenseRange(100, 1000, 200)->Unit(kMillisecond)->Complexity();
}
