#pragma once
#include <gls/auth.hpp>
#include <gls/models/calculation_create.hpp>
#include <gls/models/paginated_calculation_list.hpp>
#include <gls/models/response_calculation.hpp>
#include <gls/models/status_067.hpp>
#include <variant>
#include <unordered_map>
namespace gls {
using namespace std::literals;

class Calculation {
  const Auth& credentials;

 public:
  Calculation() = delete;
  explicit Calculation(const Auth& credentials) : credentials(credentials) {}
  std::variant<TPaginatedCalculationList, std::string> Get(
      bool favorite, bool is_history, bool is_recalculate, std::string ordering,
      std::int64_t page, std::int64_t page_size, std::int64_t project_id,
      gls::Status067 status);
  std::variant<TResponseCalculation, std::string> Post(TCalculationCreate info);
};
}  // namespace gls