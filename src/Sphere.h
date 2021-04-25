#ifndef _SPHERE_H_
#define _SPHERE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Sphere : public Shape
{
public:
    Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation);
    ~Sphere();
};

#endif