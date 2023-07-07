#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <gls/models/tractor.hpp>
#include <gls/models/axes.hpp>

namespace gls
{
    struct TTractorkGet
    {
        int64_t id;
        std::string title;
        int64_t length;
        std::string created_at;
        std::string updated_at;
        int64_t hitch_distance;
        std::vector<TAxes> axles;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
            TTractorkGet,
            id,
            title,
            length,
            created_at,
            updated_at,
            axles,
            hitch_distance,
            created_at,
            updated_at
    )
}