#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// #include <tuple>

class Window {
public:
    Window();
    Window(const Window& other) = default;
    ~Window();

    void update();

    GLFWwindow* getWindow() const { return window_ctx_; }

    // std::tuple<double, double> get_dimensions();
    // std::tuple<double, double> get_mouse_pos();
private:
    GLFWwindow* window_ctx_;
};