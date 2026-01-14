cmake_minimum_required(VERSION 3.25)

project(Crunch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(Crunch)

target_sources(Crunch
  PRIVATE
    src/core/window.cpp
)

target_include_directories(Crunch
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Crunch
  PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)

