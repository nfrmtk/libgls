#pragma once
#include <gls/auth.hpp>
#include <gls/models/cargo.hpp>
#include <gls/models/paginated_cargo_list.hpp>
#include <variant>
namespace gls {
using Response = std::pair<nlohmann::json, std::int64_t>;
class Cargo {
  const Auth& auth;

 public:
  Cargo() = delete;
  Cargo(const Auth& auth) : auth(auth) {}
  Response GetList(std::string ordering, std::int64_t page,
                   std::int64_t page_size, std::string title_icontains);
  Response Post(const models::TCargo& to_send);
  Response GetById(std::int64_t id);
  Response ChangeById(std::int64_t id, const models::TCargo& replacement);
  Response Delete(std::int64_t id);
};
}  // namespace gls