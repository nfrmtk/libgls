#pragma once
#include <gls/contianer.hpp>
struct ContainerFixture {
  gls::Container cont;
  std::int64_t id;
  ContainerFixture() = delete;
  ContainerFixture(gls::Container cont, gls::models::TContainer object)
      : cont(cont) {
    if (auto ans = cont.Post(std::move(object)); ans.second / 100 != 2)
      throw std::logic_error("something is wrong: " + to_string(ans.first));
    else
      id = ans.first["id"].get<std::int64_t>();
  }

  ~ContainerFixture() {
    cont.Delete(id);
  }
};