#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "cargo_space_report_short_info_type_report_enum.hpp"
namespace gls {
struct TCargoSpaceReportInfo {
  std::string type;
  std::string title;
  std::string uid;
  CargoSpaceReportShortInfoTypeReport pallets;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargoSpaceReportInfo, type, uid, title,
                                   pallets)
}  // namespace gls