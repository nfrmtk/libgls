#pragma once
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TUploadExcelFile {
  std::string file;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TUploadExcelFile, file)
}  // namespace gls