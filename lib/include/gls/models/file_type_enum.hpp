#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>

namespace gls {
enum class FileType { kInvalid = -1, kExcel, kPdf };
NLOHMANN_JSON_SERIALIZE_ENUM(FileType,
                             {
                                 {FileType::kInvalid, nullptr},
                                 {FileType::kExcel, "excel"},
                                 {FileType::kPdf, "pdf"},
                             })
}  // namespace gls
