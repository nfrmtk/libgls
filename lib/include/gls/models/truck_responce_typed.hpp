#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <gls/models/axes.hpp>
#include <gls/models/tractor.hpp>
#include <vector>

namespace gls
{
    struct TTruckResponceTyped
    {
        std::string resourcetype;
        int64_t id;
        std::string title;
        int64_t mass;
        int64_t carrying_capacity;
        int64_t width;
        int64_t height;
        int64_t length;
        int64_t loading_width;
        int64_t loading_height;
        int64_t loading_length;
        int64_t indentation_width;
        int64_t indentation_width_right;
        int64_t indentation_height;
        int64_t indentation_height_top;
        int64_t indentation_length;
        int64_t indentation_length_end;
        std::string created_at;
        std::string updated_at;
        bool demo;
        int64_t user;
        std::string type;
        std::string uid;
        std::vector<TAxes> axles;
        int64_t hitch_load;
        int64_t hitch_max_load;
        int64_t hitch_distance;
        TTractor tractor;
    };
}