#include <catch2/catch_test_macros.hpp>
#include <gls/cargo.hpp>

TEST_CASE("complete cargo test") {
  gls::Auth auth{{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Cargo cargo{auth};
  SECTION("post-get") {
    gls::models::TCargo thing = {123,
                                 "mytitle",
                                 12,
                                 12,
                                 12,
                                 100,
                                 false,
                                 12,
                                 false,
                                 "my",
                                 1,
                                 1,
                                 1,
                                 "red",
                                 false,
                                 "2017-07-21T17:32:28Z",
                                 "2017-07-23T17:32:28Z",
                                 1,
                                 1};
    cargo.Post(std::move(thing));
    auto res = cargo.GetById(123);
    REQUIRE(std::holds_alternative<gls::models::TCargo>(res));
    REQUIRE(std::get<gls::models::TCargo>(res).id == 123);
    REQUIRE(std::get<gls::models::TCargo>(res).color == "red");
  }
}