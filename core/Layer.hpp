#pragma once

#include <vector>
#include <string>

class Layer {
public:
    Layer(const std::string& name = "Layer")
        :name_(name) {
    }
    Layer(const Layer&) = delete;
    ~Layer() = default;

    virtual void onAttach() = 0;
    virtual void onDetach() = 0;
    virtual void update(float dt) = 0;

    [[nodiscard]] const inline std::string& getName() const { return name_; }
protected:
    std::string name_;
};

class LayerStack {
public:
    LayerStack() = default;
    LayerStack(const LayerStack&) = delete;
    ~LayerStack();

    void pushLayer(Layer* Layer);
    void popLayer(Layer* Layer);
    
    inline std::vector<Layer*>::iterator begin() { return layers_.begin(); }
    inline std::vector<Layer*>::iterator end() { return layers_.end(); }
private:
    std::vector<Layer*> layers_;
};