#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Triangle
{
public:
    Triangle(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    ~Triangle();
};

#endif