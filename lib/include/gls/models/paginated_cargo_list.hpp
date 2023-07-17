#pragma once
#include <cstdint>
#include <gls/models/calculation.hpp>
#include <gls/models/cargo.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace gls::models {
struct TPaginatedCargoList {
  std::int64_t count;
  std::string next;
  std::string previous;
  std::vector<TCargo> results;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TPaginatedCargoList, count, next, previous,
                                   results)
}  // namespace gls::models