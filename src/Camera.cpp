#include "Camera.h"

#include <iostream>

Camera::Camera(glm::vec3 _pos, float _fov, float _aspectRatio) :
    pos(_pos), fov(_fov), aspectRatio(_aspectRatio)
{}

Camera::~Camera()
{}

std::shared_ptr<std::vector<glm::vec3>> Camera::generateRays(float z, float imageWidth, float imageHeight)
{
    // Find corner position of image
    float cornerX = tan(fov / 2.0f) / (pos.z - z);
    float cornerY = tan(fov / 2.0f) / (pos.z - z);

    // Find the pixel size and offset
    float width = cornerX * 2.0f / imageWidth;
    float height = cornerY * 2.0f / imageHeight;
    float xOffset = cornerX / imageWidth;
    float yOffset = cornerY / imageHeight;

    // Generate normalized ray vectors
    std::shared_ptr<std::vector<glm::vec3>> points = std::make_shared<std::vector<glm::vec3>>();
    for(int i = 0; i < (int)imageHeight; i++)
    {
        float y = cornerY - (height * ((float)i + 1.0f)) + yOffset;
        for(int j = 0; j < (int)imageWidth; j++)
        {
            float x = cornerX - (width * ((float)j + 1.0f)) + xOffset;

            points->push_back(glm::normalize(glm::vec3(x, y, z - pos.z)));
        }
    }

    // Return vector
    return points;
}

void Camera::generateScene(Scene scene, int imageSize)
{
    // TODO
    return;
}
