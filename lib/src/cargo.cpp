#include <gls/cargo.hpp>
#include <iostream>
namespace gls {

std::variant<models::TPaginatedCargoList, std::string> gls::Cargo::GetList(
    std::string ordering, std::int64_t page, std::int64_t page_size,
    std::string title_icontains) {
  cpr::Parameters params{{"ordering", std::move(ordering)},
                         {"page", std::to_string(page)},
                         {"page_size", std::to_string(page_size)},
                         {"title_icontains", std::move(title_icontains)}};
  auto result =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(result.text);
  if (j.contains("detail"))
    return std::string{"bad request, details: "} +
           j["detail"].get<std::string>();
  else
    return j.get<models::TPaginatedCargoList>();
}
std::variant<models::TCargo, std::string> Cargo::Post(models::TCargo to_send) {
  auto body = nlohmann::json{std::move(to_send)};
  auto response = cpr::Post(cpr::Url{auth.GetBaseUrl() + "calculation/"},
                            cpr::Bearer{auth.GetCredentials()->access_token},
                            cpr::Header{headers}, cpr::Body{to_string(body)});
  std::cout << response.text << '\n';
  if (response.status_code / 100 != 2)
    return std::to_string(response.status_code) + " status code";
  auto j = nlohmann::json::parse(response.text);
  if (j.contains("detail"))
    return std::string{"bad request, details: "} +
           j["detail"].get<std::string>();
  else
    return j.get<models::TCargo>();
}

std::variant<models::TCargo, std::string> Cargo::GetById(std::int64_t id) {
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(response.text);

  if (j.contains("detail"))
    return std::string{"bad request, details: "} +
           j["detail"].get<std::string>();
  else
    return j.get<models::TCargo>();
}
std::variant<models::TCargo, std::string> Cargo::ChangeById(
    std::int64_t id, models::TCargo replacement) {
  auto body = nlohmann::json(std::move(replacement));
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Put(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token},
               cpr::Header{headers}, cpr::Body{to_string(body)});
  auto j = nlohmann::json::parse(response.text);

  if (j.contains("detail"))
    return std::string{"bad request, details: "} +
           j["detail"].get<std::string>();
  else
    return j.get<models::TCargo>();
}
std::optional<std::string> Cargo::Delete(std::int64_t id) {
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Delete(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
                  cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(response.text);

  if (j.contains("detail"))
    return std::string{"bad request, details: "} +
           j["detail"].get<std::string>();
  else
    return std::nullopt;
}

}  // namespace gls
