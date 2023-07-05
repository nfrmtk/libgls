#include <chrono>
#include <gls/date_time.hpp>
#include <nlohmann/json.hpp>
#include <string>
namespace gls {
struct TCalculation {
  std::int64_t id;
  std::int64_t project_id;
  bool is_recalculate;
  enum class CalculationStatus {
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
      {
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
          {CalculationStatus::kIrrelevant, "irrelevant"}
      })
  CalculationStatus status;
  std::string updated_at;
  bool favorite;
  std::string created_at;
  std::string provisional_completion_date;
};
static std::unordered_map<std::string, TCalculation::CalculationStatus>
    mappings{
        // todo!
    };

}  // namespace gls