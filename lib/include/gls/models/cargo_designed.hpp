#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TInfo {};
struct TCargoDesigned {
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
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCargoDesigned, title, length, width, height,
                                   mass, stacking, stacking_limit, turnover,
                                   article, margin_length, margin_width, count,
                                   color)
}  // namespace gls
