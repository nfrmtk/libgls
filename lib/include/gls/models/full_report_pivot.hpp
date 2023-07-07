#include <nlohmann/json.hpp>
#include <string>

#include "file_type_enum.hpp"

namespace gls {
struct TFullReportPivot {
  FileType file_type;
  std::string callback_url;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TFullReportPivot, file_type, callback_url)
}  // namespace gls