#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls::models {
struct TContainer {
  std::string title;
  double mass;
  double carrying_capacity;
  std::int64_t length;
  std::int64_t width;
  std::int64_t height;
  std::int64_t loading_width;
  std::int64_t loading_height;
  std::int64_t loading_length;
  std::int64_t indentation_width;
  std::int64_t indentation_width_right;
  std::int64_t indentation_height;
  std::int64_t indentation_height_top;
  std::int64_t indentation_length;
  std::int64_t indentation_length_end;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TContainer, title, length, width, height,
                                   mass, carrying_capacity, loading_width,
                                   loading_height, loading_length,
                                   indentation_width, indentation_width_right,
                                   indentation_height, indentation_height_top,
                                   indentation_length, indentation_length_end)
}  // namespace gls::models
