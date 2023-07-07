#include <cstdint>
#include <string>

#include "status_067.hpp"

namespace gls {
struct THistoryCalculation {
  std::int64_t id;
  std::string created_at;
  bool is_recalculate;
  Status067 status;
  bool favorite;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(THistoryCalculation, id, created_at,
                                   is_recalculate, status, favorite)
}  // namespace gls