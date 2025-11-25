enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
     GIT_TAG v1.17.0
)

if (MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(tests_exec
    ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/physics/physics_2d/vector2d/vector_2d_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/physics/physics_2d/rigid_body/rigid_body_test.cpp
)

target_link_libraries(tests_exec
    PRIVATE
    physics_2d
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_exec)