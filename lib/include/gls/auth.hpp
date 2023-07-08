#include <cpr/cpr.h>

#include <gls/models/auth_token.hpp>
#include <gls/models/tokens.hpp>
#include <nlohmann/json.hpp>
#include <utility>
namespace gls {
class Auth {
  TAuthToken email_password;
  std::optional<TTokens> credentials;
  static void check_if_failed(const cpr::Response& response) {
    if (response.status_code != 200) {
      throw std::runtime_error("request failure. Api responded with: " +
                               std::to_string(response.status_code) +
                               " and such json: \n" +
                               to_string(nlohmann::json::parse(response.text)));
    }
  }
  static cpr::Header headers;
  std::string base_url;

 public:
  Auth() = delete;
  explicit Auth(TAuthToken token,
                std::string base_url = "https://back.glsystem.net/api/v1/")
      : email_password(std::move(token)),
        credentials(std::nullopt),
        base_url(std::move(base_url)) {
    Login();
  }
  Auth& Login() {
    auto body = to_string(nlohmann::json(email_password));

    auto response = cpr::Post(cpr::Url{this->base_url + "auth/login/"},
                              cpr::Body{std::move(body)}, headers);
    check_if_failed(response);
    credentials = nlohmann::json::parse(response.text).get<TTokens>();
    return *this;
  }
  Auth& Logout() {
    if (!credentials.has_value() ||
        credentials->access_token_expires !=
            0) {  // todo: properly handle case when access_token_expires != 0
      return *this;
    }
    auto response = cpr::Post(cpr::Url{base_url + "auth/logout/"}, headers,
                              cpr::Bearer(credentials->access_token));
    credentials = std::nullopt;
    return *this;
  }

  [[nodiscard]] const std::optional<TTokens>& GetCredentials() const noexcept {
    return credentials;
  }
  Auth& Refresh() {
    if (!credentials.has_value()) {
      throw std::logic_error("please login first");
    }
    nlohmann::json body = nlohmann::json::object();
    body["refresh_token"] = credentials->refresh_token;

    auto response = cpr::Post(cpr::Url{base_url + "auth/refresh/"},
                              cpr::Bearer{credentials->access_token},
                              cpr::Header{headers},
                              cpr::Body{to_string(body)});
    check_if_failed(response);
    auto j = nlohmann::json::parse(std::move(response.text));
    if (!j["result"].get<bool>()) return *this;
    credentials->access_token_expires = j["access_token_expires"].get<std::int64_t>();
    credentials->access_token = j["access_token"].get<std::string>();
    return *this;
  }
  ~Auth() { Logout(); }
};

cpr::Header Auth::headers = {{"Content-Type", "application/json"}};
}  // namespace gls