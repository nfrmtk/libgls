#pragma once
#include <chrono>
#include <gls/models/status_067.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls::models {
struct TCalculation {
  std::int64_t id;
  std::int64_t project_id;
  std::string updated_at;
  std::string created_at;
  std::string provisional_completion_date;
  models::Status067 status;
  bool is_recalculate;
  bool favorite;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculation, id, project_id, updated_at,
                                   created_at, provisional_completion_date,
                                   status, is_recalculate, favorite)
}  // namespace gls::models