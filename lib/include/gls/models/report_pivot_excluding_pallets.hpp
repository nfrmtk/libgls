#pragma once
#include <chrono>
#include <gls/models/file_type_enum.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TReportPivotExcludingPallets {
  FileType file_type;
  std::string callback_url;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TReportPivotExcludingPallets, file_type,
                                   callback_url)
}  // namespace gls