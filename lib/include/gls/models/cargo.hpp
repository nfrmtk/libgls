#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls::models {
struct TCargo {
  std::int64_t id;
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
  std::int64_t count;
  std::string color;
  bool demo;
  std::string created_at;
  std::string updated_at;
  std::int64_t last_changed_user;
  std::int64_t user;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargo, id, title, length, width, height,
                                   mass, stacking, stacking_limit, turnover,
                                   article, margin_length, margin_width, count,
                                   color, demo, created_at, updated_at,
                                   last_changed_user, user)
}  // namespace gls::models
