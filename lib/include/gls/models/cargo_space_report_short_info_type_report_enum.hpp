#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls {

enum class CargoSpaceReportShortInfoTypeReport : std::int8_t {
  kInvalid = -1,
  kCargoSpaces,
  kPallets
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    CargoSpaceReportShortInfoTypeReport,
    {{CargoSpaceReportShortInfoTypeReport::kInvalid,
      nullptr},  // must always be the first, see realisation and link in chat!
     {CargoSpaceReportShortInfoTypeReport::kCargoSpaces, "cargo_spaces"},
     {CargoSpaceReportShortInfoTypeReport::kPallets, "pallets"}})
}  // namespace gls