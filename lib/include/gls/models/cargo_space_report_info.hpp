#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "pallet_report.hpp"
namespace gls {
struct TCargoSpaceReportInfo {
  std::string type;
  std::string title;
  std::string uid;
  std::vector<TPalletReport> pallets;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargoSpaceReportInfo, type, uid, title,
                                   pallets)
}  // namespace gls