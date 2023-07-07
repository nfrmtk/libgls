#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "file_type_enum.hpp"
#include "input_data.hpp"
#include "status_067.hpp"
namespace gls {
struct TCalculationWithProjectCreate {
  std::int64_t id;
  std::int64_t project;
  TInputData input_data;
  Status067 status;
  std::string callback_url;
  bool external_api;
  std::vector<FileTypeEnum> type_report;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationWithProjectCreate, id, project,
                                   input_data, status, callback_url,
                                   external_api, type_report)
}  // namespace gls