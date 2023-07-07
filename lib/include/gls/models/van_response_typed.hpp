#pragma once
#include <cstdint>
#include <gls/models/axes.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TVanResponseTyped {
  std::string resourcetype;
  std::int64_t id;
  std::string title;
  std::int64_t mass;
  std::int64_t carrying_capacity;
  std::int64_t width;
  std::int64_t height;
  std::int64_t length;
  std::int64_t loading_width;
  std::int64_t loading_height;
  std::int64_t loading_length;
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
  std::string type;
  std::string uid;
  std::vector<TAxes> axles;
  std::int64_t full_length;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
    TVanResponseTyped, resourcetype, id, title, mass, carrying_capacity, width,
    height, length, loading_width, loading_height, loading_length,
    indentation_width, indentation_width_right, indentation_height,
    indentation_height_top, indentation_length, indentation_length_end,
    created_at, updated_at, demo, user, type, uid, axles, full_length)

}  // namespace gls