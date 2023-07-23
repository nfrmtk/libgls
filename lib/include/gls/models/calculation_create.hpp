#pragma once
#include <cstdint>
#include <gls/models/input_data.hpp>
#include <gls/models/status_067.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls::models {
struct TCalculationCreate {
  std::int64_t project;
  TInputData input_data;
  Status067 status;
  bool external_api;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationCreate, project, input_data,
                                   status, external_api)
}  // namespace gls::models