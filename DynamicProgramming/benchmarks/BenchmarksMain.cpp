#ifdef RUN_BENCHMARKS
#include "Benchmarksmain.h"
#include "FibonacciBenchmark.h"
#include "benchmark/benchmark_api.h"
#include "benchmark\reporter.h"
void SetupAllBenchMarks()
{
  BENCHMARK(FibonacciRecursive)->Unit(benchmark::kMillisecond)->Arg(10)->Arg(20)->Arg(30)->Arg(40)->Arg(46)->Complexity();
  BENCHMARK(FibonacciMemonized)->DenseRange(100, 2100, 500)->Complexity();
  BENCHMARK(FibonacciDP)->DenseRange(100000, 2100000, 500000)->Complexity();
  BENCHMARK(FibonacciDPOptimized)->DenseRange(100000, 2100000, 500000)->Complexity();
}

#endif