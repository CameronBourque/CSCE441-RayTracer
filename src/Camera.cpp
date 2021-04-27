#include "Camera.h"

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
    std::shared_ptr<std::vector<glm::vec3>> rayDirs = std::make_shared<std::vector<glm::vec3>>();
    for(int i = 0; i < (int)imageHeight; i++)
    {
        float y = cornerY - (height * ((float)i + 1.0f)) + yOffset;
        for(int j = 0; j < (int)imageWidth; j++)
        {
            float x = cornerX - (width * ((float)j + 1.0f)) + xOffset;

            rayDirs->push_back(glm::normalize(glm::vec3(x, y, z - pos.z)));
        }
    }

    return rayDirs;
}

void Camera::generateScene(std::shared_ptr<Scene>& scene, float z, int imageSize)
{
    // Create image
    std::shared_ptr<Image> image = std::make_shared<Image>(imageSize, imageSize);

    // Find corner position of image
    float cornerX = tan(fov / 2.0f) / (pos.z - z);
    float cornerY = tan(fov / 2.0f) / (pos.z - z);

    // Find the pixel size and offset
    float width = cornerX * 2.0f / (float)imageSize;
    float height = cornerY * 2.0f / (float)imageSize;
    float xOffset = cornerX / (float)imageSize;
    float yOffset = cornerY / (float)imageSize;

    // Generate ray normals and build image
    for(int i = 0; i < imageSize; i++)
    {
        float y = cornerY - (height * ((float)i + 1.0f)) + yOffset;
        for(int j = 0; j < imageSize; j++)
        {
            float x = cornerX - (width * ((float)j + 1.0f)) + xOffset;
            glm::vec3 ray = glm::normalize(glm::vec3(x, y, z) - pos);

            // Get color
            glm::vec3 color = scene->computeColor(pos, ray, 0, 100);

            // Clamp color range
            int red = color.r * 255;
            if(red > 255)
            {
                red = 255;
            }
            else if(red < 0)
            {
                red = 0;
            }

            int green = color.g * 255;
            if(green > 255)
            {
                green = 255;
            }
            else if(green < 0)
            {
                green = 0;
            }

            int blue = color.b * 255;
            if(blue > 255)
            {
                blue = 255;
            }
            else if(blue < 0)
            {
                blue = 0;
            }

            // Build image
            image->setPixel(imageSize - j - 1, imageSize - i - 1, red, green, blue);
        }
    }

    // Write to file
    image->writeToFile("out.png");
}
