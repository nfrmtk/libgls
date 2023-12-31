#pragma once
#include <cstdint>
#include <gls/models/input_cargo.hpp>
#include <string>
#include <vector>

namespace gls::models {
struct TGroup {
  std::string title;
  std::int64_t pallet;
  std::vector<TInputCargo> cargoes;
  std::int64_t sort;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TGroup, title, pallet, cargoes, sort)

}  // namespace gls::models