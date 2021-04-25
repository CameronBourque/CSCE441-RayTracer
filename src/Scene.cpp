#include "Scene.h"

Scene::Scene(int _scene) :
             scene(_scene)
{
    std::shared_ptr<Shape> redSphere;
    std::shared_ptr<Shape> greenSphere;
    std::shared_ptr<Shape> blueSphere;
    std::shared_ptr<Shape> refSphere1;
    std::shared_ptr<Shape> refSphere2;
    std::shared_ptr<Shape> floor;
    std::shared_ptr<Shape> wall;

    std::shared_ptr<Light> light1;
    std::shared_ptr<Light> light2;

    switch (scene)
    {
        case 1:
        case 2:
        case 8:
            redSphere = std::make_shared<Sphere>(glm::vec3(-0.5f, 1.0f, 1.0f),
                                                 glm::vec3(1.0f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            greenSphere = std::make_shared<Sphere>(glm::vec3(0.5f, -1.0f, -1.0f),
                                                   glm::vec3(1.0f),
                                                   glm::vec3(0.0f),
                                                   glm::vec3(0.0f, 1.0f, 0.0f),
                                                   glm::vec3(1.0f, 1.0f, 0.5f),
                                                   glm::vec3(0.1f, 0.1f, 0.1f),
                                                   100.0f
            );
            shapes.push_back(greenSphere);

            blueSphere = std::make_shared<Sphere>(glm::vec3(0.0f, 1.0f, 0.0f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f),
                                                  glm::vec3(0.0f, 0.0f, 1.0f),
                                                  glm::vec3(1.0f, 1.0f, 0.5f),
                                                  glm::vec3(0.1f, 0.1f, 0.1f),
                                                  100.0f
            );
            shapes.push_back(blueSphere);

            light1 = std::make_shared<Light>(glm::vec3(-2.0f, 1.0f, 1.0f),
                                             1.0f
            );
            lights.push_back(light1);

            break;

        case 3:
            redSphere = std::make_shared<Sphere>(glm::vec3(0.5f, 0.0f, 0.5f),
                                                 glm::vec3(0.5f, 0.6f, 0.2f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            greenSphere = std::make_shared<Sphere>(glm::vec3(-0.5f, 0.0f, -0.5f),
                                                   glm::vec3(1.0f),
                                                   glm::vec3(0.0f),
                                                   glm::vec3(0.0f, 1.0f, 0.0f),
                                                   glm::vec3(1.0f, 1.0f, 0.5f),
                                                   glm::vec3(0.1f, 0.1f, 0.1f),
                                                   100.0f
            );
            shapes.push_back(greenSphere);

            floor = std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f),
                                            glm::vec3(M_PI / 2, 0.0f, 0.0f), //TODO: Y+ up
                                            glm::vec3(1.0f, 1.0f, 1.0f),
                                            glm::vec3(0.0f, 0.0f, 0.0f),
                                            glm::vec3(0.1f, 0.1f, 0.1f),
                                            0.0f
            );
            shapes.push_back(floor);

            light1 = std::make_shared<Light>(glm::vec3(1.0f, 2.0f, 2.0f),
                                             0.5f
            );
            lights.push_back(light1);

            light2 = std::make_shared<Light>(glm::vec3(-1.0f, 2.0f, -1.0f),
                                             0.5f
            );
            lights.push_back(light2);

            break;

        case 4:
        case 5:
            redSphere = std::make_shared<Sphere>(glm::vec3(-0.5f, 1.0f, 1.0f),
                                                 glm::vec3(1.0f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            blueSphere = std::make_shared<Sphere>(glm::vec3(0.0f, 1.0f, 0.0f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f),
                                                  glm::vec3(0.0f, 0.0f, 1.0f),
                                                  glm::vec3(1.0f, 1.0f, 0.5f),
                                                  glm::vec3(0.1f, 0.1f, 0.1f),
                                                  100.0f
            );
            shapes.push_back(blueSphere);

            floor = std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f),
                                            glm::vec3(0.0f, 0.0f, 0.0f), //TODO: Y+ up
                                            glm::vec3(1.0f, 1.0f, 1.0f),
                                            glm::vec3(0.0f, 0.0f, 0.0f),
                                            glm::vec3(0.1f, 0.1f, 0.1f),
                                            0.0f
            );
            shapes.push_back(floor);

            wall = std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f),
                                           glm::vec3(0.0f, 0.0f, 0.0f), //TODO: Z+ up
                                           glm::vec3(1.0f, 1.0f, 1.0f),
                                           glm::vec3(0.0f, 0.0f, 0.0f),
                                           glm::vec3(0.1f, 0.1f, 0.1f),
                                           0.0f
            );
            shapes.push_back(wall);

            refSphere1 = std::make_shared<Sphere>(glm::vec3(-0.5f, 0.0f, -0.5f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f)
            );
            shapes.push_back(refSphere1);

            refSphere2 = std::make_shared<Sphere>(glm::vec3(1.5f, 0.0f, -1.5f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f)
            );
            shapes.push_back(refSphere2);

            light1 = std::make_shared<Light>(glm::vec3(-1.0f, 2.0f, 1.0f),
                                             0.5f
            );
            lights.push_back(light1);

            light2 = std::make_shared<Light>(glm::vec3(0.5f, -0.5f, 0.0f),
                                             0.5f
            );
            lights.push_back(light2);
            break;

        case 6:
        case 7:
            //TODO: Actual shapes...

            break;

        default:
            break;
    }
}

Scene::~Scene() {}