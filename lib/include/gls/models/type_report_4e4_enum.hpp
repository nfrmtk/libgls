#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace gls
{
    enum class TypeReport4e4Enum
    {
        kInvalid = -1,
        kExcel,
        kPdf
    };
    NLOHMANN_JSON_SERIALIZE_ENUM(TypeReport4e4Enum, { {TypeReport4e4Enum::kInvalid, nullptr}, {TypeReport4e4Enum::kExcel, "excel"}, {TypeReport4e4Enum::kPdf, "pdf"} })
}