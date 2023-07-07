#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
// #include <role_type_enum.hpp>
namespace gls {
struct TCreateUser {
  std::int64_t id;
  std::string username;
  std::string email;
  std::string phone;
  std::string password;
  std::string first_name;
  std::string last_name;
  std::string company_old;
  std::string company;
  bool confirm;
  std::string confirmation_token;
  //  RoleType role_type;
  std::string promocode;
  std::string utm_source;
  std::string utm_medium;
  std::string utm_campaign;
  std::string utm_term;
  std::string utm_content;
  std::string page_wellcome;
};
static_assert(false, "remove comment slashes");
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCreateUser, id, username, email, phone,
                                   password, first_name, last_name, company_old,
                                   company, confirm, confirmation_token,
                                   promocode, utm_source, utm_medium,
                                   utm_campaign, utm_term, utm_content,
                                   page_wellcome)
}  // namespace gls