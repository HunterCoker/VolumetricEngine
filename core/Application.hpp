#pragma once

#include "Window.hpp"
#include "GuiLayer.hpp"
#include "GameLayer.hpp"

class Application {
public:
    Application(const Application&) = delete;
    ~Application();

    static Application* get();

    void run();
private:
    Window window_;
    LayerStack layerStack_;
private:
    Application();
    static Application* instance_s;
};