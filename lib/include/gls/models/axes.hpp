#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <cstdint>

namespace gls{
struct TAxes{
  std::int64_t id;
  std::string title;
  std::int64_t distance;
  std::int64_t default_load;
  std::int64_t max_load;
};
}