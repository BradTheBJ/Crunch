cmake_minimum_required(VERSION 3.25)

project(Crunch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)


FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/core/*.cpp src/*.cpp)

add_executable(Crunch ${SOURCES})

target_include_directories(Crunch PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Crunch PRIVATE ${CMAKE_BINARY_DIR}/_deps/sfml-src/include)

target_link_libraries(Crunch PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

