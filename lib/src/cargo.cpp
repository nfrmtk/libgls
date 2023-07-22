#include <gls/cargo.hpp>
namespace gls {

Response gls::Cargo::GetList(std::string ordering, std::int64_t page,
                             std::int64_t page_size,
                             std::string title_icontains) {
  cpr::Parameters params{{"ordering", std::move(ordering)},
                         {"page", std::to_string(page)},
                         {"page_size", std::to_string(page_size)},
                         {"title_icontains", std::move(title_icontains)}};
  auto result =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(result.text);
  return std::make_pair(std::move(j), result.status_code);
}
Response Cargo::Post(const models::TCargo& to_send) {
  nlohmann::json body = to_send;
  auto response = cpr::Post(cpr::Url{auth.GetBaseUrl() + "cargo/"},
                            cpr::Bearer{auth.GetCredentials()->access_token},
                            cpr::Header{headers}, cpr::Body{to_string(body)});
  auto j = nlohmann::json::parse(response.text);

  return std::make_pair(std::move(j), response.status_code);
}

Response Cargo::GetById(std::int64_t id) {
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(response.text);
  return std::make_pair(std::move(j), response.status_code);
}
Response Cargo::ChangeById(std::int64_t id, const models::TCargo& replacement) {
  auto body = nlohmann::json(std::move(replacement));
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Put(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token},
               cpr::Header{headers}, cpr::Body{to_string(body)});
  auto j = nlohmann::json::parse(response.text);

  return std::make_pair(std::move(j), response.status_code);
}
Response Cargo::Delete(std::int64_t id) {
  auto params = cpr::Parameters{{"id", std::to_string(id)}};
  auto response =
      cpr::Delete(cpr::Url{auth.GetBaseUrl() + "cargo/"}, std::move(params),
                  cpr::Bearer{auth.GetCredentials()->access_token});

  auto j = nlohmann::json::parse(response.text);
  return std::make_pair(std::move(j), response.status_code);
}

}  // namespace gls
