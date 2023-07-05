#include <string>
#include <chrono>
#include <gls/date_time.hpp>
namespace gls{
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
    DateTime updated_at;
    bool favorite;
    DateTime created_at;
    DateTime provisional_completion_date;
  };
  static std::unordered_map<std::string,TCalculation::CalculationStatus> mappings{
      //todo!
  };

}