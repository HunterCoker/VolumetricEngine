#include "Scene.hpp"

Scene::~Scene() {

}

std::shared_ptr<Scene> Scene::Load(const std::string& filepath) {
    auto scene = std::make_shared<Scene>();

    for (int y = 0; y < 7000; ++y) {
        for (int x = 0; x < 9; ++x) {
            float _x = (static_cast<float>(x) - 4.0f) / 4.0f;
            float _y = (static_cast<float>(y) - 3.0f) / 3.0f;
            scene->quads_.emplace_back(std::make_unique<Quad>(_x, _y, 0.0f, glm::vec2(0.15f, 0.15f)));
        }
    }

    return scene;
}

void Scene::update(float dt) {
    camera_.update(dt);
}