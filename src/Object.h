#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <memory>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"
#include "Triangle.h"

class Object : public Shape
{
public:
    Object(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s);
    ~Object();

    virtual float intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3& hitPos, glm::vec3& hitNor);

    virtual void addTriangles(std::vector<float>& posBuf);

private:
    std::vector<std::shared_ptr<Triangle>> triangles;
    glm::mat4 E;
    glm::mat4 IE;
    glm::mat4 ITE;
};

#endif