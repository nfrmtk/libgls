#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
struct TAuthToken {
  std::string username;
  std::string password;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TAuthToken, username, password)
}  // namespace gls
