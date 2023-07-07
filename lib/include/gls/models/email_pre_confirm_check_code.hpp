#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
// #include <role_type_enum.hpp>
namespace gls {
struct TEmailPreConfirmCheckCode {
  std::string email;
  std::string email_confirmation_code;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TEmailPreConfirmCheckCode, email,
                                   email_confirmation_code)
}  // namespace gls