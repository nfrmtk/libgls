FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

enable_testing()
file(GLOB_RECURSE SOURCES ./*cpp)

add_executable(test ${SOURCES})
add_test(NAME test COMMAND test)

target_link_libraries(test Catch2::Catch2WithMain libgls)
include(CTest)
include(Catch)
catch_discover_tests(test)
