#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TCalculationCargoes {
  std::string packed;
  std::string unpacked;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationCargoes, packed, unpacked)
}  // namespace gls