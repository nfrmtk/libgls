#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "cargo_space_report_short_info_type_report_enum.hpp"
namespace gls {
struct TCargoSpaceReportShortInfo {
  std::string type;
  std::string title;
  std::string uid;
  CargoSpaceReportShortInfoTypeReport pallets;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargoSpaceReportShortInfo, type, uid, title,
                                   pallets)
}  // namespace gls