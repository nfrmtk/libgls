#include <catch2/catch_test_macros.hpp>
#include <gls/models/calculation.hpp>

TEST_CASE("serialize_enum", "[invalid]") {
  gls::models::Status067 state;
  nlohmann::json e = 2.718;
  state = e.get<decltype(state)>();
  REQUIRE(state == gls::models::Status067::kInvalid);
}
TEST_CASE("serialize_enum", "[good]") {
  gls::models::Status067 state;
  nlohmann::json new_ = "new";
  state = new_.get<decltype(state)>();
  REQUIRE(state == gls::models::Status067::kNew);
}
