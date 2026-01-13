cmake_minimum_required(VERSION 3.25)

project(Crunch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(sfml)

file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/core/*.cpp"
)

#if(NOT SOURCES)
#    message(FATAL_ERROR "No source (.cpp) files found. Ensure sources are under src/cpp or assets/")
#endif()

add_executable(Crunch ${SOURCES})

target_include_directories(Crunch PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
#    "${CMAKE_SOURCE_DIR}/assets"
)

if(TARGET SFML::Graphics)
    set(SFML_LIBS SFML::Graphics SFML::Window SFML::System SFML::Audio)
else()
    set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
endif()

target_link_libraries(Crunch PRIVATE ${SFML_LIBS})

