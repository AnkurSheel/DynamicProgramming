#include "Includes.h"

#ifdef RUN_TESTS

#include "gtest/gtest.h"

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

#include "..\benchmarks\Benchmarksmain.h"
#include "benchmark/benchmark_api.h"

int main(int argc, char** argv)
{
  SetupAllBenchMarks();
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
  {
    return 1;
  }
  ::benchmark::RunSpecifiedBenchmarks();
}

#endif
