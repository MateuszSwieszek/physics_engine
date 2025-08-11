add_library(
    physics_2d STATIC
    src/vector2d.cpp
)

target_include_directories(physics_2d PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)