#ifndef _PLANE_H_
#define _PLANE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Plane : public Shape
{
public:
    Plane(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    Plane(glm::vec3 pos, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    ~Plane();

    virtual float intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3& hitPos, glm::vec3& hitNor);
};

#endif