#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>

namespace gls {
struct TUserTariffCreate {
  std::int64_t tariff;
  bool is_hold;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TUserTariffCreate, tariff, is_hold)

}