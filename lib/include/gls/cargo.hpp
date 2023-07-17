#pragma once
#include <gls/auth.hpp>
#include <gls/models/cargo.hpp>
#include <gls/models/paginated_cargo_list.hpp>
#include <variant>
namespace gls {
class Cargo {
  const Auth& auth;

 public:
  Cargo() = delete;
  Cargo(const Auth& auth) : auth(auth) {}
  std::variant<models::TPaginatedCargoList, std::string> GetList(
      std::string ordering, std::int64_t page, std::int64_t page_size,
      std::string title_icontains);
  std::variant<models::TCargo, std::string> Post(models::TCargo to_send);
  std::variant<models::TCargo, std::string> GetById(std::int64_t id);
  std::variant<models::TCargo, std::string> ChangeById(
      std::int64_t id, models::TCargo replacement);
  std::optional<std::string> Delete(std::int64_t id);
};
}  // namespace gls