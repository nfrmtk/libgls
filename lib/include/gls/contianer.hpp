#pragma once
#include <gls/auth.hpp>
#include <gls/models/container.hpp>
#include <optional>
namespace gls {

class Container {
  const Auth& auth;

 public:
  Container() = delete;
  Container(const Auth& auth)
      : auth(auth) {
  }
  Response Get(std::optional<bool> demo = std::nullopt,
               std::optional<std::int64_t> page = std::nullopt,
               std::optional<std::int64_t> page_size = std::nullopt,
               std::optional<std::string> title_icontains = std::nullopt);
  Response GetById(std::int64_t id);
  Response Post(models::TContainer object);
  std::int64_t Delete(std::int64_t id);
};

}  // namespace gls