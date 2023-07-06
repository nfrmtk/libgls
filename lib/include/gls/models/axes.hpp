#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TAxes {
  std::int64_t id;
  std::string title;
  std::int64_t distance;
  std::int64_t default_load;
  std::int64_t max_load;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TAxes, id, title, distance, default_load,
                                   max_load)
}  // namespace gls