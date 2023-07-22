#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls::models {
struct TCargo {
  std::string title;
  std::int64_t length;
  std::int64_t width;
  std::int64_t height;
  double mass;
  bool stacking;
  std::int64_t stacking_limit;
  bool turnover;
  std::string article;
  std::int64_t margin_length;
  std::int64_t margin_width;
  std::string color;
  bool demo;
  std::int64_t last_changed_user;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargo, title, length, width, height, mass,
                                   stacking, stacking_limit, turnover, article,
                                   margin_length, margin_width, color, demo,
                                   last_changed_user)
}  // namespace gls::models
