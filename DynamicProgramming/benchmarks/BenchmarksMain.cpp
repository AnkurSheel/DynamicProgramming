#ifdef RUN_BENCHMARKS
#include "Benchmarksmain.h"
#include "FibonacciBenchmark.h"
#include "benchmark/benchmark_api.h"
#include "benchmark\reporter.h"

using namespace benchmark;

void SetupAllBenchMarks()
{
  BENCHMARK(FibonacciRecursive)->Arg(10)->Arg(20)->Arg(30)->Arg(40)->Unit(kMillisecond)->Complexity();

  BENCHMARK(FibonacciMemonized)->DenseRange(1000, 21000, 5000)->Unit(kMillisecond)->Complexity();

  BENCHMARK(FibonacciDP)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();

  BENCHMARK(FibonacciDPOptimized)->DenseRange(100000, 2100000, 500000)->Unit(kMillisecond)->Complexity();
}

#endif