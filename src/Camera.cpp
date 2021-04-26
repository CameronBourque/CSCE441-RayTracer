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
    // Generate projection, view and camera matrices
    std::shared_ptr<MatrixStack> MV = std::make_shared<MatrixStack>();
    MV->loadIdentity();
    MV->multMatrix(glm::perspective(fov, aspectRatio, 0.1f, 1000.0f));
    glm::mat4 P = MV->topMatrix();
    MV->loadIdentity();
    MV->multMatrix(glm::lookAt(pos, pos, glm::vec3(0.0f, 1.0f, 0.0f)));
    glm::mat4 V = MV->topMatrix();
    glm::mat4 C = inverse(V);

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
            glm::vec3 p = glm::vec3(x, y, z);
            glm::vec3 ray = glm::normalize(glm::vec3(x, y, z) - pos);

            // Get color
            glm::vec3 color = scene->computeColor(p, ray, 0, 1000);

            // Build image
            image->setPixel(i, j, (int)(color.r * 255), (int)(color.g * 255), (int)(color.b * 255));
        }
    }

    // Write to file
    image->writeToFile("out.png");
}
