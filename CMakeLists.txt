cmake_minimum_required(VERSION 3.26)
project(JSON_parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(JSON_parser main.cpp
        "JSON parser class.cpp"
)

add_library(cparse_lib_core STATIC IMPORTED)
set_property(TARGET cparse_lib_core PROPERTY
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/cparse/core-shunting-yard.o)

add_library(cparse_lib_features STATIC IMPORTED)
set_property(TARGET cparse_lib_features PROPERTY
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/cparse/builtin-features.o)

target_link_libraries(JSON_parser cparse_lib_core cparse_lib_features)