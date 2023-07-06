#pragma once
#include <cstdint>
#include <gls/models/cargo_designed.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
namespace gls {

struct TGroupDesigned {
  std::string title;
  std::int64_t pallet;
  std::vector<TCargoDesigned> cargoes;
  std::int64_t sort;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TGroupDesigned, title, pallet, cargoes, sort)

}  // namespace gls