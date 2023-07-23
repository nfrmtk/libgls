#pragma once
#include <gls/auth.hpp>
#include <nlohmann/json.hpp>
#include <utility>
namespace gls {
class Project {
  const Auth& auth;

 public:
  Project() = delete;
  Project(const Auth& credentials)
      : auth(credentials) {
  }
  Response Get(std::optional<std::string> ordering = std::nullopt,
               std::optional<std::int64_t> page = std::nullopt,
               std::optional<std::int64_t> page_size = std::nullopt,
               std::optional<std::string> title_icontains = std::nullopt);
  Response Post(const std::string& name);
  std::int64_t Delete(std::int64_t id);
};
}  // namespace gls