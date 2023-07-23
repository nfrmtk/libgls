#include "project.hpp"

#include <catch2/catch_test_macros.hpp>
TEST_CASE("complete project test") {
  gls::Auth auth{{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Project project(auth);
  SECTION("basic") {
    ProjectFixture fixture{std::move(project), "ci-run-123"};
    auto [j, status] = fixture.proj_.Get();
    REQUIRE(status / 100 == 2);
    REQUIRE(j["results"][0]["title"].get<std::string>() == "ci-run-123");
  }
}