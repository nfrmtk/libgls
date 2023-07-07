#pragma once
#include <string>
#include <nlohmann/json.hpp>
namespace gls
{
    struct TUploadExcelFile
    {
        std::string file;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TUploadExcelFile, file)
}