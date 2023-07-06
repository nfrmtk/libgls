#pragma once
#include <cstdint>
#include <gls/models/file_type_enum.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculationReportList {
  FileTypeEnum status;
  std::string uid;
  std::string callback_url;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculationReportList, status, uid,
                                   callback_url)
}  // namespace gls