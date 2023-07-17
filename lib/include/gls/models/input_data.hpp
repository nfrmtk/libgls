#pragma once
#include <gls/models/group.hpp>

namespace gls::models {
struct TInputData {
  std::vector<std::int64_t> cargo_spaces;
  std::vector<TGroup> groups;
  bool user_sort;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TInputData, cargo_spaces, groups, user_sort)

}  // namespace gls::models