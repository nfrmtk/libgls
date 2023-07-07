#pragma once
#include <cstdint>
#include <gls/models/input_data.hpp>
#include <gls/models/status_067.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculationCreate {
  std::int64_t id;
  std::int64_t project;
  TInputData input_data;
  Status067 status;
  std::string callback_url;
  bool external_api;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationCreate, id, project, input_data,
                                   status, callback_url, external_api)
}  // namespace gls