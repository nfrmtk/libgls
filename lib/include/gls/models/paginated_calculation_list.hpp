#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "calculation.hpp"

namespace gls::models {
struct TPaginatedCalculationList {
  std::int64_t count;
  std::string next;
  std::string previous;
  std::vector<TCalculation> results;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TPaginatedCalculationList, count, next,
                                   previous, results)
}  // namespace gls::models