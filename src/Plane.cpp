#include "Plane.h"

Plane::Plane(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
             Shape(pos, scale, rotation, kd, ks, ka, s)
{}

Plane::~Plane() {}

Plane::Plane(glm::vec3 pos, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
             Shape(pos, rotation, kd, ks, ka, s)
{}

float Plane::intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor)
{
    // Implement basic plane intersection
    glm::vec3 n = rotation;
    float t = glm::dot(n, pos - p) / glm::dot(n, v);
    if(t > t0 && t < t1)
    {
        hitPos = p + (t * v);
        hitNor = n;
        return t;
    }
    return t1 + 1.0f;
}
