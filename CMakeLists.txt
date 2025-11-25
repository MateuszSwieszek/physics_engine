cmake_minimum_required(VERSION 3.14)
project(physics_engine VERSION 0.0.1 LANGUAGES CXX)

option(BUILD_TESTS "Build unit tests" OFF)
option(BUILD_MAIN_EXEC "Build main executable" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Dodaj podkatalogi — każdy ma swój CMakeLists.txt
add_subdirectory(physics/physics2d/vector)
add_subdirectory(physics/physics2d/rigid_body)

if(BUILD_MAIN_EXEC)
    add_subdirectory(main)
endif()

# # Jeżeli chcesz mieć testy
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()