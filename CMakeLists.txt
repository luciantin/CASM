cmake_minimum_required(VERSION 3.20)
project(CASM C)
set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/includes)
add_subdirectory(includes/casm)

add_executable(CASM main.c)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC  casm)
target_include_directories(${PROJECT_NAME} PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/includes/casm"
        )
