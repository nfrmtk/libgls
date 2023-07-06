#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "cargo_space_report_info.hpp"
namespace gls {
struct TCalculationReportList {
  std::vector<TCargoSpaceReportInfo> cargo_spaces;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationReportList, cargo_spaces)
}  // namespace gls