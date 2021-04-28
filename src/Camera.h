#ifndef CAMERA_H_
#define CAMERA_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include "MatrixStack.h"
#include "Image.h"

// epsilon = 1e-5

class Camera
{
public:
    Camera(glm::vec3 _pos, float _fov, float _aspectRatio);
    ~Camera();

    void generateScene(std::shared_ptr<Scene>& scene, float z, int imageSize);

private:
    glm::vec3 pos;
    float fov;
    float aspectRatio;
};

#endif