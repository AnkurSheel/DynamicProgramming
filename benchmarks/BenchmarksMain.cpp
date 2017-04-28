#include "CustomConsoleReporter.h"
#include "benchmark/benchmark_api.h"
#include "benchmark\reporter.h"

using namespace benchmark;

int main(int argc, char** argv)
{
  cCustomConsoleReporter consoleReporter;
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
  {
    return 1;
  }
  ::benchmark::RunSpecifiedBenchmarks(&consoleReporter);
}
