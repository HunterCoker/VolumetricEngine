#include "GameLayer.hpp"

#include "../scene/Scene.hpp"

void GameLayer::onAttach() {
    renderer_.init();
    activeScene_ = Scene::Load("../assets/scenes/main_menu.yml");
    renderer_.beginScene();
}

void GameLayer::onDetach() {

}

void GameLayer::update(float dt) {



}