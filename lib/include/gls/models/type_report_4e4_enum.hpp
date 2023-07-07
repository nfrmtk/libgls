#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace gls {
enum class TypeReport4e4Enum { excel = 0, pdf };
NLOHMANN_JSON_SERIALIZE_ENUM(TypeReport4e4Enum,
                             {{TypeReport4e4Enum::excel, "excel"},
                              {TypeReport4e4Enum::pdf, "pdf"}})
}  // namespace gls