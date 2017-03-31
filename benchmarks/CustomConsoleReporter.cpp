#include "CustomConsoleReporter.h"
#include <stdarg.h>
#include <iomanip>
#include <memory>
#include <sstream>
#include "benchmark/colorprint.h"
#include "benchmark/complexity.h"
#include "benchmark/string_util.h"

using namespace benchmark;
using namespace std;

void cCustomConsoleReporter::PrintHeader(const Run& run)
{
  stringstream ss;
  ss << setw(name_field_width_) << std::left << "Benchmark Name";
  ss << std::right;
  ss << setw(15) << "Running Time";
  ss << setw(17) << "Iterations/sec";

  if (run.bytes_per_second > 0)
  {
    ss << setw(13) << " Memory/sec";
  }
  if (run.items_per_second > 0)
  {
    ss << setw(17) << " Items/sec";
  }
  if (!run.counters.empty())
  {
    ss << " UserCounters...";
  }
  string line = string(ss.str().length(), '-');
  GetOutputStream() << line << "\n" << ss.str() << "\n" << line << "\n";
}

void cCustomConsoleReporter::PrintRunData(const Run& result)
{
  auto& Out = GetOutputStream();
  auto name_color = (result.report_big_o || result.report_rms) ? COLOR_BLUE : COLOR_GREEN;
  if (!result.report_rms)
  {
    ColorPrintf(Out, name_color, "%-*s ", name_field_width_, result.benchmark_name.c_str());
  }

  if (result.error_occurred)
  {
    ColorPrintf(Out, COLOR_RED, "ERROR OCCURRED: \'%s\'", result.error_message.c_str());
    ColorPrintf(Out, COLOR_DEFAULT, "\n");
    return;
  }

  const double real_time = result.GetAdjustedRealTime();
  const double cpu_time = result.GetAdjustedCPUTime();

  if (result.report_big_o)
  {
    std::string big_o = GetBigOString(result.complexity);
    ColorPrintf(Out, COLOR_YELLOW, "%s", big_o.c_str());
  }
  else if (result.report_rms)
  {
    // ColorPrintf(Out, COLOR_YELLOW, "%10.0f %% %10.0f %% ", real_time * 100, cpu_time * 100);
  }
  else
  {
    const char* timeLabel = GetTimeUnitString(result.time_unit);
    // ColorPrintf(Out, COLOR_YELLOW, "%10.0f %s %10.0f %s ", real_time, timeLabel, cpu_time, timeLabel);
    ColorPrintf(Out, COLOR_YELLOW, "%10.0f %s ", real_time, timeLabel);
    ColorPrintf(Out, COLOR_CYAN, "%15lld", result.iterations);

    for (auto& c : result.counters)
    {
      auto const& s = HumanReadableNumber(c.second.value);
      ColorPrintf(Out, COLOR_DEFAULT, " %s=%s", c.first.c_str(), s.c_str());
    }

    // Format bytes per second
    std::string rate;
    if (result.bytes_per_second > 0)
    {
      rate = StrCat(" ", HumanReadableNumber(result.bytes_per_second), "B/s");
      ColorPrintf(Out, COLOR_DEFAULT, " %*s", 13, rate.c_str());
    }

    // Format items per second
    std::string items;
    if (result.items_per_second > 0)
    {
      items = StrCat(" ", HumanReadableNumber(result.items_per_second));
      ColorPrintf(Out, COLOR_DEFAULT, " %*s", 17, items.c_str());
    }

    if (!result.report_label.empty())
    {
      ColorPrintf(Out, COLOR_DEFAULT, " %s", result.report_label.c_str());
    }
  }
  ColorPrintf(Out, COLOR_DEFAULT, "\n");
}
