#pragma once
#include <cstdint>
#include <gls/models/status_067.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculationLastCalcResponse {
  std::int64_t id;
  Status067 status;
  std::string start_time;
  std::string provisional_completion_date;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationLastCalcResponse, id, status,
                                   start_time, provisional_completion_date)
}  // namespace gls