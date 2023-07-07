#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls {

enum class ReportStatus : std::int8_t  {
  kInvalid = -1,
  kCreated,
  kGenerating,
  kGenerating_uid,
  kError_completed,
  kCompleted,
  kAwaiting_calc
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ReportStatus,
    {{ReportStatus::kInvalid,
      nullptr},
     {ReportStatus::kCreated, "created"},
     {ReportStatus::kGenerating, "generating"},
     {ReportStatus::kGenerating_uid, "generating_uid"},
     {ReportStatus::kError_completed, "error_completed"},
     {ReportStatus::kCompleted, "completed"},
     {ReportStatus::kAwaiting_calc, "awaiting_calc"},})
}   // namespace gls