#include <gls/contianer.hpp>

namespace gls {
using namespace std::literals;
Response Container::Get(std::optional<bool> demo,
                        std::optional<std::int64_t> page,
                        std::optional<std::int64_t> page_size,
                        std::optional<std::string> title_icontains) {
  cpr::Parameters params;
  if (demo.has_value())
    params.Add({"demo", (*demo) ? "true" : "false"});
  if (page.has_value())
    params.Add({"page", std::to_string(*page)});
  if (page_size.has_value())
    params.Add({"page_size", std::to_string(*page_size)});
  if (title_icontains.has_value())
    params.Add({"title_icontains", *title_icontains});
  auto result =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "container/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  return std::make_pair(nlohmann::json::parse(result.text), result.status_code);
}
Response Container::GetById(std::int64_t id) {
  auto result = cpr::Get(
      cpr::Url{auth.GetBaseUrl() + "container/"s + std::to_string(id) + '/'},
      cpr::Bearer{auth.GetCredentials()->access_token});
  return std::make_pair(nlohmann::json::parse(result.text), result.status_code);
}
Response Container::Post(gls::models::TContainer object) {
  nlohmann::json body = object;
  auto result = cpr::Post(cpr::Url{auth.GetBaseUrl() + "container/"},
                          cpr::Bearer{auth.GetCredentials()->access_token},
                          cpr::Header{headers}, cpr::Body{to_string(body)});
  auto j = nlohmann::json::parse(result.text);
  return std::make_pair(std::move(j), result.status_code);
}

std::int64_t Container::Delete(std::int64_t id) {
  auto result = cpr::Delete(
      cpr::Url{auth.GetBaseUrl() + "container/"s + std::to_string(id) + '/'},
      cpr::Bearer{auth.GetCredentials()->access_token});
  return result.status_code;
}
}  // namespace gls