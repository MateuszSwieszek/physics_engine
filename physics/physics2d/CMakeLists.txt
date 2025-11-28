add_library(
    physics_2d STATIC
    vector/src/vector2d.cpp
    rigid_body/src/rigid_body.cpp
)

target_include_directories(physics_2d PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vector/includes
    ${CMAKE_CURRENT_SOURCE_DIR}/rigid_body/includes
)