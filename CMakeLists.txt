cmake_minimum_required(VERSION 3.10)
project(c_engine)
add_executable(c_engine main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(c_engine PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}/rendering"
	"${PROJECT_BINARY_DIR}/engine"
)

add_subdirectory(rendering)
target_link_libraries(c_engine rendering)
find_library(SDL3 libSDL3)
find_library(SDL3_image libSDL3_image)
target_link_libraries(c_engine SDL3 SDL3_image)
