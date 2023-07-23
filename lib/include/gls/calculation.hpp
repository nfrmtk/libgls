#pragma once
#include <gls/auth.hpp>
#include <gls/models/calculation_create.hpp>
#include <gls/models/paginated_calculation_list.hpp>
#include <gls/models/response_calculation.hpp>
#include <gls/models/status_067.hpp>
#include <unordered_map>
#include <optional>

namespace gls {
using namespace std::literals;

class Calculation {
  const Auth& credentials;

 public:
  Calculation() = delete;
  explicit Calculation(const Auth& credentials)
      : credentials(credentials) {
  }
  Response Get(std::optional<bool> favorite = std::nullopt,
               std::optional<bool> is_history = std::nullopt,
               std::optional<bool> is_recalculate = std::nullopt,
               std::optional<std::string> ordering = std::nullopt,
               std::optional<std::int64_t> page = std::nullopt,
               std::optional<std::int64_t> page_size = std::nullopt,
               std::optional<std::int64_t> project_id = std::nullopt,
               std::optional<gls::models::Status067> status = std::nullopt);
  Response Post(models::TCalculationCreate info);
  std::int64_t Delete(std::int64_t id);
};
}  // namespace gls