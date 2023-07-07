#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

#include "form_type_enum.hpp"
// #include <role_type_enum.hpp>
namespace gls {
struct TFeedback {
  std::int64_t id;
  std::string fullname;
  std::string phone;
  std::string email;
  std::string message;
  FormType form_type;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TFeedback, id, fullname, phone, email,
                                   message, form_type)
}  // namespace gls