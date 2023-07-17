#include <gls/calculation.hpp>
namespace gls {
std::string to_string(bool b) { return b ? "true"s : "false"s; }
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
std::variant<models::TPaginatedCalculationList, std::string> Calculation::Get(
    bool favorite, bool is_history, bool is_recalculate, std::string ordering,
    std::int64_t page, std::int64_t page_size, std::int64_t project_id,
    gls::models::Status067 status) {
  cpr::Parameters params{{"favorite", to_string(favorite)},
                         {"is_history", to_string(is_history)},
                         {"is_recalculate", to_string(is_recalculate)},
                         {"ordering", std::move(ordering)},
                         {"page_size", std::to_string(page_size)},
                         {"project_id", std::to_string(project_id)},
                         {"status", to_string(status)}};
  auto response = cpr::Get(
      cpr::Url{credentials.GetBaseUrl() + "calculation/"}, std::move(params),
      cpr::Bearer{credentials.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(response.text);

  if (j.contains("detail"))
    return j["detail"].get<std::string>();
  else {
    try {
      return j.get<models::TPaginatedCalculationList>();
    } catch (const nlohmann::json::exception& ex) {
      return std::string{"bad json, explanation: "} + ex.what();
    }
  }
}

std::variant<models::TResponseCalculation, std::string> Calculation::Post(
    gls::models::TCalculationCreate info) {
  auto body = nlohmann::json{std::move(info)};
  auto response =
      cpr::Post(cpr::Url{credentials.GetBaseUrl() + "calculation/"},
                cpr::Header{headers}, cpr::Body{to_string(body)},
                cpr::Bearer{credentials.GetCredentials()->access_token});
  auto j = nlohmann::json::parse(response.text);
  if (j.contains("detail"))
    return j["detail"].get<std::string>();
  else {
    try {
      return j.get<models::TResponseCalculation>();
    } catch (const nlohmann::json::exception& ex) {
      return std::string{"bad json, explanation: "} + ex.what();
    }
  }
}
}  // namespace gls