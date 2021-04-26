#ifndef SCENE_H_
#define SCENE_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"
#include "Sphere.h"
#include "Light.h"
#include "Plane.h"

class Scene
{
public:
    Scene(int _scene);
    ~Scene();

    glm::vec3 computeColor(glm::vec3 p, glm::vec3 v, float t0, float t1);
    bool hit(glm::vec3 p, glm::vec3 v, float t0, float t1, std::shared_ptr<Shape>& obj, glm::vec3& hitPos,
             glm::vec3& hitNor);

private:
    int scene;
    std::vector<std::shared_ptr<Shape>> shapes;
    std::vector<std::shared_ptr<Light>> lights;
};

#endif