#include "GameLayer.hpp"

#include "Scene.hpp"

void GameLayer::onAttach() {
	activeScene_ = Scene::Load("../assets/scenes/main_menu.yml");
    renderer_.setActiveScene(activeScene_);
}

void GameLayer::onDetach() {

}

void GameLayer::update(float dt) {
    activeScene_->update(dt);

	renderer_.render();
}