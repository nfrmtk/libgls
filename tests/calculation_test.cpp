#include <catch2/catch_test_macros.hpp>
#include <gls/calculation.hpp>
TEST_CASE("deleted ctor") {
  gls::Auth auth{{ std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Calculation calc(auth);
  SECTION("random parameters result in no answer")
  {
    auto response = calc.Get(true, true, true, "sad", 1,1,1,gls::models::Status067::kQueueRecalculation);
    REQUIRE(std::holds_alternative<std::string>(response));
  }
}