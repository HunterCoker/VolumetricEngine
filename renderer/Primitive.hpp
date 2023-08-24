#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#define MAX_QUADS 10000

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;
    float texID;
};

class Primitive {

};

class Quad : Primitive {
public:
    Quad(float x = 0.0f, float y = 0.0f, float z = 0.0f, glm::vec2 size = glm::vec2(1.0f, 1.0f), float texID = 0.0f) {
        botLeft.position = glm::vec3(x - size.x * 0.5f, y - size.y * 0.5f, z);
        botLeft.color = glm::vec3(1.0f, 0.0f, 0.0f);
        botLeft.uv = glm::vec2(0.0f, 0.0f);
        botLeft.texID = texID;

        botRight.position = glm::vec3(x + size.x * 0.5f, y - size.y * 0.5f, z);
        botRight.color = glm::vec3(0.0f, 1.0f, 0.0f);
        botRight.uv = glm::vec2(1.0f, 0.0f);
        botRight.texID = texID;

        topRight.position = glm::vec3(x + size.x * 0.5f, y + size.y * 0.5f, z);
        topRight.color = glm::vec3(0.0f, 0.0f, 1.0f);
        topRight.uv = glm::vec2(1.0f, 1.0f);
        topRight.texID = texID;

        topLeft.position = glm::vec3(x - size.x * 0.5f, y + size.y * 0.5f, z);
        topLeft.color = glm::vec3(1.0f, 1.0f, 0.0f);
        topLeft.uv = glm::vec2(0.0f, 1.0f);
        topLeft.texID = texID;
    }
public:
    Vertex botLeft, botRight, topRight, topLeft;
};
