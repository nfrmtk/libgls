#include <gtest/gtest.h>

#include <gls/models/calculation.hpp>

TEST(serialize_enum, invalid) {
  gls::CalculationStatus state;
  nlohmann::json e = 2.718;
  state = e.get<decltype(state)>();
  ASSERT_EQ(state, gls::CalculationStatus::kInvalid);
}
TEST(serialize_enum, good) {
  gls::CalculationStatus state;
  nlohmann::json new_ = "new";
  state = new_.get<decltype(state)>();
  ASSERT_EQ(state, gls::CalculationStatus::kNew);
}
