#include <catch2/catch_test_macros.hpp>
#include <gls/calculation.hpp>
#include <gls/contianer.hpp>
#include "calculation.hpp"
TEST_CASE("calculation") {
  gls::Auth auth{{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Project project(auth);
  gls::Container container(auth);
  std::int64_t max_id = 0;
  auto all = container.Get();
  REQUIRE(all.second / 100 == 2);
  for (auto& container : all.first["results"]) {
    max_id = std::max(container["id"].get<std::int64_t>(), max_id);
  }
  auto object = gls::models::TContainer{
      .title = "test-" + std::to_string(max_id + 1),
      .mass = 10,
      .carrying_capacity = 1,
      .length = 100,
      .width = 100,
      .height = 100,
      .loading_width = 100,
      .loading_height = 100,
      .loading_length = 100,
      .indentation_width = 0,
      .indentation_width_right = 0,
      .indentation_height = 0,
      .indentation_height_top = 0,
      .indentation_length = 0,
      .indentation_length_end = 0
  };
  gls::Calculation calc(auth);
  CalculationFixture calcfixture(
      std::make_unique<ProjectFixture>(project, "calculation-ci"),
      std::make_unique<ContainerFixture>(container, std::move(object)), calc);

  SECTION("basic") {
    auto ans = calcfixture.calc.Get();
    REQUIRE(ans.second / 100 == 2);
    auto rezs = ans.first["results"];
    REQUIRE(rezs.is_array());
    REQUIRE(rezs.size() > 0);

    REQUIRE(std::find_if(rezs.begin(), rezs.end(),
                         [id = calcfixture.id](const nlohmann::json& j) {
                           return j["id"].get<std::int64_t>() == id;
                         }) != rezs.end());
  }
}