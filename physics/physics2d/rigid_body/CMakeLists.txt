add_library(
    rigid_body STATIC
    src/rigid_body.cpp
)

target_include_directories(rigid_body PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(rigid_body PUBLIC physics_2d)