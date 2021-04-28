#ifndef _SPHERE_H_
#define _SPHERE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Shape.h"
#include "MatrixStack.h"

class Sphere : public Shape
{
public:
    Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation);
    ~Sphere();

    virtual float intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3& hitPos, glm::vec3& hitNor);

private:
    glm::mat4 E;
    glm::mat4 IE;
    glm::mat4 ITE;
};

#endif