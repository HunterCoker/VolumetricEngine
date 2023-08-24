#pragma once

#include "Layer.hpp"

#include "../renderer/Renderer.hpp"

class GameLayer : public Layer {
public:
    void onAttach() override;
    void onDetach() override;
    void update(float dt) override;
private:
    std::shared_ptr<Scene> activeScene_;
    Renderer renderer_;
};