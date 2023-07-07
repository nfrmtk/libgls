#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

#include "cargo_space_list_enum.hpp"
namespace gls {
struct TContainer {
  std::int64_t id;
  std::string title;
  double mass;
  double carrying_capacity;
  std::int64_t length;
  std::int64_t width;
  std::int64_t height;
  std::int64_t loading_width;
  std::int64_t loading_height;
  std::int64_t indentation_width;
  std::int64_t indentation_width_right;
  std::int64_t indentation_height;
  std::int64_t indentation_height_top;
  std::int64_t indentation_length;
  std::int64_t indentation_length_end;
  std::string created_at;
  std::string updated_at;
  bool demo;
  std::int64_t user;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TContainer, id, title, length, width, height,
                                   mass, carrying_capacity, loading_width,
                                   loading_height, indentation_width,
                                   indentation_width_right, indentation_height,
                                   indentation_height_top, indentation_length,
                                   indentation_length_end, created_at,
                                   updated_at, demo, user)
}  // namespace gls
