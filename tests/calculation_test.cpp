#include <gtest/gtest.h>

#include <gls/models/calculation.hpp>

TEST(serialize_enum, invalid) {
  gls::Status067Enum state;
  nlohmann::json e = 2.718;
  state = e.get<decltype(state)>();
  ASSERT_EQ(state, gls::Status067Enum::kInvalid);
}
TEST(serialize_enum, good) {
  gls::Status067Enum state;
  nlohmann::json new_ = "new";
  state = new_.get<decltype(state)>();
  ASSERT_EQ(state, gls::Status067Enum::kNew);
}
