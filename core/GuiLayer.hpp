#pragma once

#include "Layer.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class GuiLayer : public Layer {
public:
    void onAttach() override;
    void onDetach() override;
    void update(float dt) override;
private:

};