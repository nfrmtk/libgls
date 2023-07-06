#pragma once
#include <cstdint>
#include <gls/models/input_data_designed.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculationDesignedCreate {
  std::int64_t id;
  std::string status;
  std::int64_t project;
  TInputDataDesigned input_data;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationDesignedCreate, id, status,
                                   project, input_data)
}  // namespace gls