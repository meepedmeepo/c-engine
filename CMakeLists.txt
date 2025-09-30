cmake_minimum_required(VERSION 3.10)
project(c_engine)
add_executable(c_engine main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(imgui_src "dependencies/imgui-1.92.3")
target_include_directories(c_engine PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}/rendering"
	"${PROJECT_BINARY_DIR}/engine"
	"${PROJECT_BINARY_DIR}/management"
	"${PROJECT_BINARY_DIR}/ui"
)

add_library(imgui
	"${imgui_src}/imgui.cpp"
	"${imgui_src}/imgui_draw.cpp"
	"${imgui_src}/imgui_tables.cpp"
	"${imgui_src}/imgui_widgets.cpp"
	"${imgui_src}/backends/imgui_impl_sdlrenderer3.cpp"
	"${imgui_src}/backends/imgui_impl_sdl3.cpp"
)

target_include_directories(imgui PUBLIC "${imgui_src}" "${imgui_src}/backends")

add_subdirectory(rendering)
target_link_libraries(c_engine rendering)

add_subdirectory(management)
target_link_libraries(c_engine management)

add_subdirectory(ui)
target_link_libraries(c_engine ui)

find_library(SDL3 libSDL3)
find_library(SDL3_image libSDL3_image)
target_link_libraries(c_engine SDL3 SDL3_image imgui)
