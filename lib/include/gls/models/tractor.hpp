#pragma once
#include <cstdint>
#include <gls/models/axes.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace gls {
struct TTractor {
  int64_t id;
  std::string title;
  int64_t length;
  int64_t hitch_distance;
  int64_t mass;
  std::string created_at;
  std::string updated_at;
  std::vector<TAxes> axles;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TTractor, id, title, length, hitch_distance,
                                   mass, created_at, updated_at, axles)
}  // namespace gls