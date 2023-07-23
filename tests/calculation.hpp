#pragma once
#include "project.hpp"
#include "container.hpp"
#include <gls/calculation.hpp>
struct CalculationFixture {
  std::unique_ptr<ProjectFixture> pfix;
  std::unique_ptr<ContainerFixture> cfix;
  gls::Calculation calc;
  std::int64_t id;
  CalculationFixture() = delete;
  CalculationFixture(decltype(pfix)&& pfix, decltype(cfix)&& cfix,
                     gls::Calculation calc)
      : pfix(std::move(pfix)),
        cfix(std::move(cfix)),
        calc(std::move(calc)) {
    auto vec = std::vector{gls::models::TInputCargo{.title = "ci-thing",
                                                    .length = 1000,
                                                    .width = 1000,
                                                    .height = 1000,
                                                    .mass = 1234,
                                                    .stacking = true,
                                                    .stacking_limit = 0,
                                                    .turnover = true,
                                                    .article = "ci-article",
                                                    .margin_length = 1000,
                                                    .margin_width = 1000,
                                                    .count = 1,
                                                    .color = "#FF0000"}};
    gls::models::TGroup g = {.title = "ci-group",
                             .pallet = 0,
                             .cargoes = {{.title = "ci-thing",
                                          .length = 50,
                                          .width = 50,
                                          .height = 50,
                                          .mass = 1234,
                                          .stacking = true,
                                          .stacking_limit = 0,
                                          .turnover = true,
                                          .article = "ci-article",
                                          .margin_length = 50,
                                          .margin_width = 50,
                                          .count = 1,
                                          .color = "#FF0000"}},
                             .sort = 1};
    gls::models::TCalculationCreate info = {
        .project = this->pfix->getId(),
        .input_data =
            {
                .cargo_spaces = {this->cfix->id},
                .groups = {std::move(g)},
                .user_sort = true,
            },
        .status = gls::models::Status067::kNew,
        .external_api = true,
    };
    auto result = calc.Post(std::move(info));
    if (result.second / 100 != 2)
      throw std::logic_error("something is not right: " +
                             to_string(result.first));
    else
      id = result.first["id"].get<std::int64_t>();
  }
  ~CalculationFixture() {
    calc.Delete(id);
  }
};