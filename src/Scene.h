#ifndef _SCENE_H_
#define _SCENE_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>

#include "Camera.h"
#include "Shape.h"
#include "Sphere.h"
#include "Light.h"
#include "Plane.h"

class Scene
{
public:
    Scene(int _scene);
    ~Scene();

private:
    int scene;
    std::vector<std::shared_ptr<Shape>> shapes;
    std::vector<std::shared_ptr<Light>> lights;
};

#endif