#include <cpr/cpr.h>

#include <gls/models/auth_token.hpp>
#include <gls/models/tokens.hpp>
#include <nlohmann/json.hpp>
#include <utility>
namespace gls {
class Auth {
  TAuthToken email_password;
  std::optional<TTokens> required_to_work;
  cpr::Session session;
  static void check_if_failed(const cpr::Response& response) {
    if (response.status_code != 200) {
      throw std::runtime_error("request failure. Api responded with: " +
                               std::to_string(response.status_code) +
                               " and such json: \n" +
                               to_string(nlohmann::json::parse(response.text)));
    }
  }

 public:
  std::string base_url;
  std::string content_type;
  Auth() = delete;
  explicit Auth(TAuthToken token,
                std::string base_url = "https://back.glsystem.net/api/v1/")
      : email_password(std::move(token)),
        required_to_work(std::nullopt),
        session(),
        base_url(std::move(base_url)),
        content_type("application/json") {
    Login();
  }
  Auth& Login() {
    session.UpdateHeader({{"Content-Type", content_type}});
    session.SetUrl(cpr::Url{base_url + "auth/login/"});
    auto body = to_string(nlohmann::json(email_password));
    session.SetBody(cpr::Body{std::move(body)});
    auto response = session.Post();
    check_if_failed(response);
    auto credentials = nlohmann::json::parse(response.text);
    required_to_work = std::make_optional(credentials.get<TTokens>());
    session.SetBearer(required_to_work->access_token);
    return *this;
  }
  Auth& Logout() {
    if (!required_to_work.has_value() ||
        required_to_work->access_token_expires !=
            0) {  // todo: properly handle case when access_token_expires != 0
      return *this;
    }
    session.SetUrl(cpr::Url{base_url + "auth/logout/"});
    auto response = session.Post();
    required_to_work = std::nullopt;
    return *this;
  }

  const std::optional<TTokens>& GetCredentials() const noexcept {
    return required_to_work;
  }
  Auth& ConfigureSession(
      const std::function<void(cpr::Session&)>& configurator) {
    configurator(session);
    return *this;
  }
  Auth& Relogin(){
    if (!required_to_work.has_value()) {
      throw std::logic_error("please login first");
    }
    session.SetUrl(cpr::Url{base_url + "auth/relogin/"});
    auto response = session.Post();
    check_if_failed(response);
    auto j = nlohmann::json::parse(std::move(response.text));
    auto [access_token, access_token_expires, result] = j.get<std::tuple<std::string, std::int64_t, bool>>();
    required_to_work->access_token_expires = access_token_expires;
    required_to_work->access_token = access_token;
  }
  ~Auth() { Logout(); }
};
}  // namespace gls