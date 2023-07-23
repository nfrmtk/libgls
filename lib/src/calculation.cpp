#include <gls/calculation.hpp>
namespace gls {
std::string to_string(bool b) {
  return b ? "true"s : "false"s;
}
std::string to_string(gls::models::Status067 status) {
  using namespace models;
  switch (status) {
    case Status067::kIrrelevant:
      return "irrelevant"s;
    case Status067::kInvalid:
      throw std::logic_error(
          "Status067::kInvalid value shouldn't be serialized");
    case Status067::kNew:
      return "new"s;
    case Status067::kInQueue:
      return "in_queue"s;
    case Status067::kCalculating:
      return "calculating"s;
    case Status067::kSuccess:
      return "success"s;
    case Status067::kError:
      return "error"s;
    case Status067::kDesigned:
      return "designed"s;
    case Status067::kForRecalculation:
      return "for_recalculation"s;
    case Status067::kRecalculation:
      return "recalculation"s;
    case Status067::kCancel:
      return "cancel"s;
    case Status067::kQueueRecalculation:
      return "queue_recalculation"s;
  }
}
Response Calculation::Get(std::optional<bool> favorite,
                          std::optional<bool> is_history,
                          std::optional<bool> is_recalculate,
                          std::optional<std::string> ordering,
                          std::optional<std::int64_t> page,
                          std::optional<std::int64_t> page_size,
                          std::optional<std::int64_t> project_id,
                          std::optional<gls::models::Status067> status) {
  cpr::Parameters params;
  if (favorite.has_value())
    params.Add({"demo", (*favorite) ? "true" : "false"});
  if (page.has_value())
    params.Add({"page", std::to_string(*page)});
  if (project_id.has_value())
    params.Add({"page", std::to_string(*project_id)});
  if (page_size.has_value())
    params.Add({"page_size", std::to_string(*page_size)});
  if (ordering.has_value())
    params.Add({"title_icontains", *ordering});
  if (is_history.has_value())
    params.Add({"is_history", (*is_history) ? "true" : "false"});
  if (is_recalculate.has_value())
    params.Add({"is_recalculate", (*is_recalculate) ? "true" : "false"});
  if (status.has_value())
    params.Add({"status", to_string(*status)});
  auto response = cpr::Get(
      cpr::Url{credentials.GetBaseUrl() + "calculation/"}, std::move(params),
      cpr::Bearer{credentials.GetCredentials()->access_token});
  return std::make_pair(nlohmann::json::parse(response.text),
                        response.status_code);
}

Response Calculation::Post(gls::models::TCalculationCreate info) {
  nlohmann::json body = std::move(info);
  auto response =
      cpr::Post(cpr::Url{credentials.GetBaseUrl() + "calculation/"},
                cpr::Header{headers}, cpr::Body{to_string(body)},
                cpr::Bearer{credentials.GetCredentials()->access_token});
  return std::make_pair(nlohmann::json::parse(response.text),
                        response.status_code);
}
std::int64_t Calculation::Delete(std::int64_t id) {
  return cpr::Delete(cpr::Url{credentials.GetBaseUrl() + "calculation/"s +
                              std::to_string(id) + '/'},
                     cpr::Bearer{credentials.GetCredentials()->access_token})
      .status_code;
}
}  // namespace gls