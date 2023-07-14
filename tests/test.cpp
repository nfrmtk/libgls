#include <catch2/catch_test_macros.hpp>
#include <gls/all.hpp>

TEST_CASE("hello-world test", "[string not empty]") {
  REQUIRE(!hello().empty());
}
