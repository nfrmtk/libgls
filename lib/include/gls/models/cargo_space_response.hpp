#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <variant>

#include "van_response_typed.hpp"
namespace gls {

// todo: idk how to implement
using TCargoSpaceResponse = std::variant<TVanResponseTyped, std::string>;
}  // namespace gls
