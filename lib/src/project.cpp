#include <gls/project.hpp>

namespace gls {
using namespace std::literals;
Response Project::Post(const std::string& name) {
  nlohmann::json body;
  body["title"] = name;
  auto response = cpr::Post(cpr::Url{auth.GetBaseUrl() + "project/"},
                            cpr::Bearer{auth.GetCredentials()->access_token},
                            cpr::Header{headers}, cpr::Body{to_string(body)});
  auto j = nlohmann::json::parse(response.text);

  return std::make_pair(std::move(j), response.status_code);
}
Response Project::Get(std::optional<std::string> ordering,
                      std::optional<std::int64_t> page,
                      std::optional<std::int64_t> page_size,
                      std::optional<std::string> title_icontains) {
  cpr::Parameters params;
  if (ordering.has_value())
    params.Add({"demo", *ordering});
  if (page.has_value())
    params.Add({"page", std::to_string(*page)});
  if (page_size.has_value())
    params.Add({"page_size", std::to_string(*page_size)});
  if (title_icontains.has_value())
    params.Add({"title_icontains", *title_icontains});
  auto result =
      cpr::Get(cpr::Url{auth.GetBaseUrl() + "project/"}, std::move(params),
               cpr::Bearer{auth.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(result.text);
  return std::make_pair(std::move(j), result.status_code);
}
std::int64_t Project::Delete(std::int64_t id) {
  auto response = cpr::Delete(
      cpr::Url{auth.GetBaseUrl() + "project/"s + std::to_string(id) + '/'},
      cpr::Bearer{auth.GetCredentials()->access_token});

  return response.status_code;
}
}  // namespace gls