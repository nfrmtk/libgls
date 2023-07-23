#include <catch2/catch_test_macros.hpp>
#include <gls/contianer.hpp>

#include "container.hpp"

TEST_CASE("complete container test") {
  gls::Auth auth{{std::getenv("EMAIL"), std::getenv("PASSWORD")}};
  gls::Container cont(auth);
  SECTION("post-get") {
    std::int64_t max_id = 0;
    auto all = cont.Get().first;
    for (auto& container : all["results"]) {
      max_id = std::max(container["id"].get<std::int64_t>(), max_id);
    }
    auto object =
        gls::models::TContainer{.title = "test-" + std::to_string(max_id + 1),
                                .mass = 10,
                                .carrying_capacity = 1,
                                .length = 100,
                                .width = 100,
                                .height = 100,
                                .loading_width = 100,
                                .loading_height = 100,
                                .loading_length = 100,
                                .indentation_width = 0,
                                .indentation_width_right = 0,
                                .indentation_height = 0,
                                .indentation_height_top = 0,
                                .indentation_length = 0,
                                .indentation_length_end = 0};
    auto fixture = ContainerFixture(cont, std::move(object));
    auto res = fixture.cont.GetById(fixture.id);
    REQUIRE(res.second / 100 == 2);
    REQUIRE(res.first["title"].get<std::string>() ==
            "test-" + std::to_string(max_id + 1));
  };
}