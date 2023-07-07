#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <gls/models/tractor.hpp>
#include <gls/models/axes.hpp>

namespace gls
{
    struct TTractorkCreateUpdate
    {
        std::string title;
        int64_t length;
        int64_t mass;
        int64_t hitch_distance;
        std::vector<TAxes> axles;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
            TTractorkCreateUpdate,
            title,
            length,
            mass,
            axles,
            hitch_distance
    )
}