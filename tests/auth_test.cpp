#include <catch2/catch_test_macros.hpp>
#include <gls/auth.hpp>
using namespace std::literals;
TEST_CASE("ctor", "[not throw]") {
  REQUIRE_NOTHROW(gls::Auth({std::getenv("EMAIL"), std::getenv("PASSWORD")}));
}

TEST_CASE("ctor", "[throw]") {
  REQUIRE_THROWS_AS(
      gls::Auth({std::getenv("EMAIL") + "sad"s, std::getenv("PASSWORD")}),
      std::runtime_error);
}

TEST_CASE("complete Auth test", "[Auth]") {
  gls::Auth auth_{
      gls::models::TAuthToken{std::getenv("EMAIL"), std::getenv("PASSWORD")}};

  SECTION("all credentials change after consecutive Login call") {
    auto credentials_saved = auth_.GetCredentials().value();
    auth_.Login();
    const auto& new_credentials = auth_.GetCredentials().value();
    REQUIRE(credentials_saved.refresh_token != new_credentials.refresh_token);
    REQUIRE(credentials_saved.access_token != new_credentials.access_token);
  }

  SECTION("Refresh call only changes access token") {
    auto credentials_saved = auth_.GetCredentials().value();
    auth_.Refresh();
    REQUIRE(credentials_saved.access_token !=
            auth_.GetCredentials()->access_token);
    REQUIRE(credentials_saved.refresh_token_expires ==
            auth_.GetCredentials()->refresh_token_expires);
    REQUIRE(credentials_saved.refresh_token ==
            auth_.GetCredentials()->refresh_token);
  }
  SECTION("Can't use api after logout!") {
    REQUIRE_NOTHROW(auth_.Refresh());
    auth_.Logout();
    REQUIRE_THROWS_AS(auth_.Refresh(), std::logic_error);
  }
}
