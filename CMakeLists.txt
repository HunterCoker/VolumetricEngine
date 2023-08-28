cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

project(VolumetricEngine VERSION 0.1.0 LANGUAGES C CXX)

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
	"${CORE_SOURCES_DIR}/main.cpp"
	"${CORE_SOURCES_DIR}/Application.cpp"
	"${CORE_SOURCES_DIR}/Window.cpp"
	"${CORE_SOURCES_DIR}/Scene.cpp"
	"${CORE_SOURCES_DIR}/Layer.cpp"
	"${CORE_SOURCES_DIR}/GuiLayer.cpp"
	"${CORE_SOURCES_DIR}/GameLayer.cpp")
set(RENDERER_SOURCES
	"${RENDERER_SOURCES_DIR}/Shader.cpp"
	"${RENDERER_SOURCES_DIR}/Texture.cpp"
	"${RENDERER_SOURCES_DIR}/Camera.cpp"
	"${RENDERER_SOURCES_DIR}/Primitive.cpp"
	"${RENDERER_SOURCES_DIR}/Renderer.cpp"
	"${RENDERER_SOURCES_DIR}/VertexArray.cpp"
	"${RENDERER_SOURCES_DIR}/Buffers.cpp")
add_subdirectory("./vendor/glfw")

add_executable(VolumetricEngine
	${CORE_SOURCES}
	${RENDERER_SOURCES} ${IMGUI_SOURCES}
	"vendor.cpp"
	"./vendor/glad/src/glad.c")

target_include_directories(${PROJECT_NAME}
	PRIVATE "./vendor/glad/include"
	PRIVATE "./vendor/glfw/includes"
	PRIVATE "./vendor/glm"
	PRIVATE "./vendor/stb"
	PRIVATE "./vendor/imgui"
	PRIVATE "./vendor/imgui/backends"
	PRIVATE "./vendor/tinygltf")

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw)
