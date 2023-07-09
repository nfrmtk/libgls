#include <gtest/gtest.h>

#include <gls/auth.hpp>
using namespace std::literals;

bool operator!=(const gls::TTokens& first, const gls::TTokens& second) {
  return first.access_token_expires != second.access_token_expires ||
         first.access_token != second.access_token ||
         first.refresh_token != second.refresh_token ||
         first.refresh_token_expires != second.refresh_token_expires ||
         first.token_type != second.token_type;
}
TEST(ctor, all_correct) {
  ASSERT_NO_THROW(gls::Auth({std::getenv("EMAIL"), std::getenv("PASSWORD")}));
}

TEST(ctor, incorrect_email) {
  ASSERT_THROW(
      gls::Auth({std::getenv("EMAIL") + "sad"s, std::getenv("PASSWORD")}),
      std::runtime_error);
}

struct AuthFixture : ::testing::Test {
  gls::Auth auth_{
      gls::TAuthToken{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
};

TEST_F(AuthFixture, second_login) {
  auto credentials_saved = auth_.GetCredentials().value();
  auth_.Login();
  ASSERT_TRUE(credentials_saved != auth_.GetCredentials().value());
}

TEST_F(AuthFixture, refresh) {
  auto credentials_saved = auth_.GetCredentials().value();
  auth_.Refresh();
  ASSERT_TRUE(credentials_saved != auth_.GetCredentials().value());
  ASSERT_EQ(credentials_saved.refresh_token_expires,
            auth_.GetCredentials()->refresh_token_expires);
  ASSERT_EQ(credentials_saved.refresh_token,
            auth_.GetCredentials()->refresh_token);
}

TEST_F(AuthFixture, logout){
  ASSERT_NO_THROW(auth_.Refresh());
  auth_.Logout();
  ASSERT_THROW(auth_.Refresh(), std::logic_error);
}