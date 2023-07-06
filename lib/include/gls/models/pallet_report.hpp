#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace gls {
struct TPalletReport {
  std::string title;
  std::string uid;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TPalletReport, uid, title)
}  // namespace gls