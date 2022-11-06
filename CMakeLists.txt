cmake_minimum_required(VERSION 3.20)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

project("stl_reader-playground")

# Config mode means do not use CMake official configuration.
# Here i use my own "openssl-config.cmake"
find_package(stl_reader CONFIG REQUIRED)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} stl_reader::stl_reader)

add_custom_command(
TARGET ${PROJECT_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/samples
        ${CMAKE_CURRENT_BINARY_DIR}/samples)