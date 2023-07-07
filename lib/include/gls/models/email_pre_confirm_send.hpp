#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
// #include <role_type_enum.hpp>
namespace gls {
struct TEmailPreConfirmSend {
  std::string email;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TEmailPreConfirmSend, email)
}  // namespace gls