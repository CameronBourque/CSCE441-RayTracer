#include "Plane.h"

Plane::Plane(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
             Shape(pos, scale, rotation, kd, ks, ka, s)
{}

Plane::~Plane() {}

Plane::Plane(glm::vec3 pos, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
             Shape(pos, rotation, kd, ks, ka, s)
{}
