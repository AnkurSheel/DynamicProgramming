#include <sstream>
#include <string>
#include "..\src\EditDistance.h"
#include "benchmark/benchmark_api.h"

using namespace benchmark;
using namespace std;

namespace Benchmarks
{
  class EditDistance : public Fixture
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
    void SetState(State& state)
    {
      stringstream ss;
      state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char) * 2);
      state.SetItemsProcessed(state.iterations() * state.range(0));
      state.SetComplexityN(state.range(0));
    }

  protected:
    cEditDistance m_EditDistance;
    char* m_string1;
    char* m_string2;
  };

  BENCHMARK_DEFINE_F(EditDistance, Recursive)(State& state)
  {
    int EditDistance;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(EditDistance = m_EditDistance.Recursive(m_string1, m_string2));
    }
    SetState(state);
  }

  //  *******************************************************************************************************************
  BENCHMARK_DEFINE_F(EditDistance, Memonized)(State& state)
  {
    int EditDistance;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(EditDistance = m_EditDistance.Memonized(m_string1, m_string2));
    }
    SetState(state);
  }

  //  *******************************************************************************************************************
  BENCHMARK_DEFINE_F(EditDistance, DP)(State& state)
  {
    int EditDistance;
    while (state.KeepRunning())
    {
      benchmark::DoNotOptimize(EditDistance = m_EditDistance.DP(m_string1, m_string2));
    }
    SetState(state);
  }

  BENCHMARK_REGISTER_F(EditDistance, Recursive)->DenseRange(10, 14, 2)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(EditDistance, Memonized)->DenseRange(100, 1000, 200)->Unit(kMillisecond)->Complexity();

  BENCHMARK_REGISTER_F(EditDistance, DP)->DenseRange(100, 1000, 200)->Unit(kMillisecond)->Complexity();
}
