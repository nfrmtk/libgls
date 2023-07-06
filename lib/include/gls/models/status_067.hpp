#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls {

enum class Status067Enum : std::int8_t {
  kInvalid = -1,
  kNew,
  kInQueue,
  kCalculating,
  kSuccess,
  kError,
  kDesigned,
  kForRecalculation,
  kRecalculation,
  kCancel,
  kQueueRecalculation,
  kIrrelevant
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    Status067Enum,
    {{Status067Enum::kInvalid,
      nullptr},  // must always be the first, see realisation and link in chat!
     {Status067Enum::kNew, "new"},
     {Status067Enum::kInQueue, "in_queue"},
     {Status067Enum::kCalculating, "calculating"},
     {Status067Enum::kSuccess, "success"},
     {Status067Enum::kError, "error"},
     {Status067Enum::kDesigned, "calculating"},
     {Status067Enum::kForRecalculation, "for_recalculation"},
     {Status067Enum::kRecalculation, "recalculation"},
     {Status067Enum::kCancel, "cancel"},
     {Status067Enum::kQueueRecalculation, "queue_recalculation"},
     {Status067Enum::kIrrelevant, "irrelevant"}})
}  // namespace gls