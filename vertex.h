#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class vertex
{
public:
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec4 color;
    glm::vec2 texcoord;

    vertex() : position(), normal(), color(), texcoord() {}

    vertex(float x, float y, float z, float u, float v, const glm::vec4& diff, float nx, float ny, float nz)
        : position(x, y, z), normal(nx, ny, nz), color(diff), texcoord(u, v) {}

    vertex(float x, float y, float z, float u, float v, const glm::vec4& diff, glm::vec3 norm = glm::vec3())
        : position(x, y, z), normal(norm), color(diff), texcoord(u, v) {}

    vertex(float x, float y, float z, const glm::vec2& st, const glm::vec4& diff, glm::vec3 norm = glm::vec3())
        : position(x, y, z), normal(norm), color(diff), texcoord(st) {}

    vertex(const glm::vec3& pos, const glm::vec2& st, const glm::vec4& diff, const glm::vec3& norm = glm::vec3())
        : position(pos), normal(norm), color(diff), texcoord(st) {}
};

#endif // VERTEX_H
