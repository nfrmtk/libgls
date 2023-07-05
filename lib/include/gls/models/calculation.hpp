#include <chrono>
#include <gls/date_time.hpp>
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