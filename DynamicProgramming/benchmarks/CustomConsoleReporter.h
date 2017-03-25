#ifndef CustomReporter_H__
#define CustomReporter_H__

#ifdef RUN_BENCHMARKS
#include "benchmark\reporter.h"

class cCustomConsoleReporter 
  : public benchmark::ConsoleReporter
{
  virtual void PrintHeader(const Run& run) override;
  virtual void PrintRunData(const Run& result) override;
};
#endif // RUN_BENCHMARKS

#endif  // CustomReporter_H__
