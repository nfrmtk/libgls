#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls {

enum class RoleType : std:int8_t  {
  kInvalid = -1,
  kPartner,
  kUser
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    RoleType,
    {{RoleType::kInvalid,
      nullptr},
     {RoleType::kPartner, "partner"},
     {RoleType::kUser, "user"}})
}   // namespace gls