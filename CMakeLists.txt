cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

project(volumetric_engine VERSION 0.1.0 LANGUAGES C CXX)

set(CORE_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/core")
set(RENDERER_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/renderer")

set(IMGUI_SOURCES
	"./vendor/imgui/imgui.cpp"
	"./vendor/imgui/imgui_draw.cpp"
	"./vendor/imgui/imgui_tables.cpp"
	"./vendor/imgui/imgui_widgets.cpp"
	"./vendor/imgui/backends/imgui_impl_glfw.cpp"
	"./vendor/imgui/backends/imgui_impl_opengl3.cpp")
set(CORE_SOURCES
	"${CORE_SOURCES_DIR}/main.cpp")
set(RENDERER_SOURCES
	"${RENDERER_SOURCES_DIR}/shader.cpp"
	"${RENDERER_SOURCES_DIR}/texture.cpp"
	"${RENDERER_SOURCES_DIR}/camera.cpp")

add_executable(volumetric_engine ${CORE_SOURCES} ${RENDERER_SOURCES} ${IMGUI_SOURCES} vendor.cpp glad.c)

target_include_directories(${PROJECT_NAME}
	PRIVATE "~/dev/dependencies/glad/include"
	PRIVATE "./vendor/stb"
	PRIVATE "./vendor/imgui"
	PRIVATE "./vendor/imgui/backends"
	PRIVATE "./vendor/tinygltf")

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw)