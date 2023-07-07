#pragma once
#include <gls/models/axes.hpp>
#include <gls/models/tractor.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TTractorkCreateUpdate {
  std::string title;
  int64_t length;
  int64_t mass;
  int64_t hitch_distance;
  std::vector<TAxes> axles;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TTractorkCreateUpdate, title, length, mass,
                                   axles, hitch_distance)
}  // namespace gls