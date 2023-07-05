FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()
file(GLOB_RECURSE SOURCES ./*cpp)

add_executable(test ${SOURCES})
add_test(NAME test COMMAND test)

target_link_libraries(test GTest::gtest_main libgls)
gtest_discover_tests(test)
