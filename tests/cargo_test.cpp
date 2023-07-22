#include <catch2/catch_test_macros.hpp>
#include <gls/cargo.hpp>

TEST_CASE("complete cargo test") {
  gls::Auth auth{{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Cargo cargo{auth};
  SECTION("post-get") {
    gls::models::TCargo thing = {"string", 32767,        32767,    32767,       100,
                                 true,    12,        true, "string", 32767,
                                 32767,        "#498BCe", true, 213};
    auto [j, status] = cargo.Post(std::move(thing));
    REQUIRE(status / 100 == 2);
    REQUIRE(j["title"].get<std::string>() == "string"); // same as thing's field

    auto [newj, newstatus] = cargo.GetById(j["id"].get<std::int64_t>());
    REQUIRE(status / 100 == 2);
    REQUIRE(j["title"].get<std::string>() == "string");
  }
}