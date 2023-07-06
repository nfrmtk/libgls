#pragma once
#include <cstdint>
#include <gls/models/group_designed.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace gls {
struct TInputDataDesigned {
  std::vector<std::int64_t> cargo_spaces;
  std::vector<TGroupDesigned> groups;
  bool user_sort;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TInputDataDesigned, cargo_spaces, groups,
                                   user_sort)
}  // namespace gls