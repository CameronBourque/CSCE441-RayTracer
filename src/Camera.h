#ifndef _CAMERA_H_
#define _CAMERA_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"

class Camera
{
public:
    Camera(glm::vec3 _pos, float _fov, float _aspectRatio);
    ~Camera();

    std::shared_ptr<std::vector<glm::vec3>> generateRays(float z, float imageWidth, float imageHeight);

    void generateScene(Scene scene, int imageSize);

private:
    glm::vec3 pos;
    float fov;
    float aspectRatio;
};

#endif