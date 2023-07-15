#pragma once
#include <cpr/cpr.h>

#include <gls/models/auth_token.hpp>
#include <gls/models/tokens.hpp>
#include <nlohmann/json.hpp>
#include <utility>
namespace gls {
void check_if_failed(const cpr::Response& response);
static cpr::Header headers = {{"Content-Type", "application/json"}};

class Auth {
  models::TAuthToken email_password;
  std::optional<TTokens> credentials;
  std::string base_url;

 public:
  Auth() = delete;
  explicit Auth(models::TAuthToken token,
                std::string base_url = "https://back.glsystem.net/api/v1/")
      : email_password(std::move(token)),
        credentials(std::nullopt),
        base_url(std::move(base_url)) {
    Login();
  }
  Auth& Login();
  Auth& Logout();

  [[nodiscard]] const std::optional<TTokens>& GetCredentials() const noexcept {
    return credentials;
  }
  [[nodiscard]] const std::string& GetBaseUrl() const noexcept {
    return base_url;
  }
  Auth& Refresh();
  ~Auth() { Logout(); }
};

}  // namespace gls