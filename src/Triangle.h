#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>

#include "MatrixStack.h"
#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::mat4 _E);
    ~Triangle();

    virtual float intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor);

private:
    glm::vec3 vert1;
    glm::vec3 vert2;
    glm::vec3 vert3;

    glm::mat4 E;
    glm::mat4 IE;
    glm::mat4 ITE;
};

#endif