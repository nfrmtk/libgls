#pragma once
#include <chrono>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
enum class CalculationStatus : int8_t {
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
struct TCalculation {
  std::int64_t id;
  std::int64_t project_id;
  std::string updated_at;
  std::string created_at;
  std::string provisional_completion_date;
  CalculationStatus status;
  bool is_recalculate;
  bool favorite;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TCalculation, id, project_id, updated_at,
                                   created_at, provisional_completion_date,
                                   status, is_recalculate, favorite)
}  // namespace gls