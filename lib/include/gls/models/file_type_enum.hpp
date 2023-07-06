#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>

namespace gls {
enum class FileTypeEnum { kInvalid = -1, kExcel, kPdf };
NLOHMANN_JSON_SERIALIZE_ENUM(FileTypeEnum,
                             {
                                 {FileTypeEnum::kInvalid, nullptr},
                                 {FileTypeEnum::kExcel, "excel"},
                                 {FileTypeEnum::kPdf, "pdf"},
                             })
}  // namespace gls
