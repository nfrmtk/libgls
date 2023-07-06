#pragma once
#include <gls/models/input_cargo.hpp>
#include <vector>
#include <string>
#include <cstdint>

namespace gls{
struct TGroup{
  std::string title;
  std::int64_t pallet;
  std::vector<TInputCargo> cargoes;
  std::int64_t sort;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TGroup , title, pallet, cargoes, sort)

}