#include "Triangle.h"

Triangle::Triangle(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka,
                   float s) :
                   Shape(pos, scale, rotation, kd, ks, ka, s)
{}

Triangle::~Triangle() {}
