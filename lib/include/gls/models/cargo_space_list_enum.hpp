#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls::models {

enum class CargoSpaceList { kInvalid = -1, kPallet, kContainer, kVan, kTruck };
NLOHMANN_JSON_SERIALIZE_ENUM(CargoSpaceList,
                             {{CargoSpaceList::kInvalid, nullptr},
                              {CargoSpaceList::kPallet, "pallet"},
                              {CargoSpaceList::kContainer, "container"},
                              {CargoSpaceList::kVan, "van"},
                              {CargoSpaceList::kTruck, "truck"}})
}  // namespace gls::models