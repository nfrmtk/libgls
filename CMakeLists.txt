cmake_minimum_required(VERSION 3.25)
project(gls_wrapper CXX )

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(lib)
add_subdirectory(tests)
add_executable(gls_wrapper play.cpp lib/include/gls/all.hpp)

target_link_libraries(gls_wrapper libgls)
