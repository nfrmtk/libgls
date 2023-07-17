#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls::models {

enum class Status067 : std::int8_t {
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
    Status067,
    {{Status067::kInvalid,
      nullptr},  // must always be the first, see realisation and link in chat!
     {Status067::kNew, "new"},
     {Status067::kInQueue, "in_queue"},
     {Status067::kCalculating, "calculating"},
     {Status067::kSuccess, "success"},
     {Status067::kError, "error"},
     {Status067::kDesigned, "calculating"},
     {Status067::kForRecalculation, "for_recalculation"},
     {Status067::kRecalculation, "recalculation"},
     {Status067::kCancel, "cancel"},
     {Status067::kQueueRecalculation, "queue_recalculation"},
     {Status067::kIrrelevant, "irrelevant"}})
}  // namespace gls::models