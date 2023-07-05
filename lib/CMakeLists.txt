file(GLOB_RECURSE SOURCES ./*pp)


add_library(libgls OBJECT ${SOURCES})
set_target_properties(libgls PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(libgls PUBLIC ./include/)
target_link_libraries(libgls PUBLIC cpr::cpr nlohmann_json::nlohmann_json)