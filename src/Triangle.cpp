#include "Triangle.h"

Triangle::Triangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::mat4 _E) :
                   Shape(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f),
                         glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f), 0.0f),
                   vert1(v1),
                   vert2(v2),
                   vert3(v3)
{
    E = _E;
    IE = glm::inverse(E);
    ITE = glm::transpose(IE);
}

Triangle::~Triangle() {}

float Triangle::intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor)
{
    glm::vec3 edge1;
    glm::vec3 edge2;
    glm::vec3 tVec;
    glm::vec3 pVec;
    glm::vec3 qVec;
    float det;
    float iDet;

    edge1 = vert2 - vert1;
    edge2 = vert3 - vert1;

    // TODO: blah blah blah....

    return t0 + 1.0f;
}
