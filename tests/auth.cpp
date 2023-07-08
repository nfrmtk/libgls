#include <gtest/gtest.h>

#include <gls/auth.hpp>
TEST(auth, passing) {
  ASSERT_NO_THROW(gls::Auth({std::getenv("EMAIL"), std::getenv("PASSWORD")}));
}
