#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>


namespace gls{
struct TAdvantage {
  std::int64_t id;
  std::string description;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TAdvantage, id, description)
}


