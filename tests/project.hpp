#pragma once
#include <gls/project.hpp>
#include <memory>
class ProjectFixture {
 public:
  gls::Project proj_;
  ProjectFixture() = delete;
  ProjectFixture(gls::Project  main, const std::string& title)
      : proj_(main),
        title(title) {
    if (auto p = proj_.Post(title); p.second / 100 != 2) {
      throw std::logic_error("something is not right, " + to_string(p.first));
    } else {
      id = p.first["id"].get<std::int64_t>();
    }
  }
  ~ProjectFixture() {
    if (id) proj_.Delete(getId());
  }
  std::int64_t getId() const noexcept {
    return id;
  }


 private:
  std::string title;
  std::int64_t id;
};