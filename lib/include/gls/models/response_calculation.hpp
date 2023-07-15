#pragma once
#include <chrono>
#include <gls/models/status_067.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls::models {
struct TResponseCalculation {
  std::int64_t id;
  std::int64_t project;
  Status067 status;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TResponseCalculation, id, project, status)
}  // namespace gls