#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculationUpdate {
  std::int64_t id;
  std::string created_at;
  bool favorite;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationUpdate, id, favorite, created_at)
}  // namespace gls