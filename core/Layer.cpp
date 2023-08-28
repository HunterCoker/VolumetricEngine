#include "Layer.hpp"

LayerStack::~LayerStack() {
    for (auto layer : layers_)
        delete layer;
}

void LayerStack::pushLayer(Layer* layer) {
    layer->onAttach();
    layers_.push_back(layer);
}

void LayerStack::popLayer(Layer* layer) {
    layer->onDetach();
    for (std::size_t i = 0; i < layers_.size(); ++i) {
        if (layers_[i] == layer)
            layers_.erase(layers_.begin() + i);
    }
}