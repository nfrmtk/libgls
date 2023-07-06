#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
namespace gls {

enum class CalculationStatus : std::int8_t {
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
    CalculationStatus,
    {{CalculationStatus::kInvalid,
      nullptr},  // must always be the first, see realisation and link in chat!
     {CalculationStatus::kNew, "new"},
     {CalculationStatus::kInQueue, "in_queue"},
     {CalculationStatus::kCalculating, "calculating"},
     {CalculationStatus::kSuccess, "success"},
     {CalculationStatus::kError, "error"},
     {CalculationStatus::kDesigned, "calculating"},
     {CalculationStatus::kForRecalculation, "for_recalculation"},
     {CalculationStatus::kRecalculation, "recalculation"},
     {CalculationStatus::kCancel, "cancel"},
     {CalculationStatus::kQueueRecalculation, "queue_recalculation"},
     {CalculationStatus::kIrrelevant, "irrelevant"}})
}