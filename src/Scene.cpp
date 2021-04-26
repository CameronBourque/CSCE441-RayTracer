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
            //TODO: Actual shapes... (teapot, bunny, etc)

            light1 = std::make_shared<Light>(glm::vec3(-1.0f, 2.0f, 1.0f),
                                             1.0f
            );
            lights.push_back(light1);
            break;

        default:
            break;
    }
}

Scene::~Scene() {}

glm::vec3 Scene::computeColor(glm::vec3 p, glm::vec3 v, float t0, float t1)
{
    std::shared_ptr<Shape> obj;
    glm::vec3 hitPos(0.0f);
    glm::vec3 hitNor(0.0f);
    if(hit(p, v, t0, t1, obj, hitPos, hitNor))
    {
        glm::vec3 color = obj->getKA();
        for(std::shared_ptr<Light> light : lights)
        {
            glm::vec3 l = glm::normalize(light->getPos() - hitPos);
            glm::vec3 e = glm::normalize(p - hitPos);
            glm::vec3 h = glm::normalize(l + e);

            glm::vec3 kd = obj->getKD() * glm::max(glm::dot(l, v), 0.0f);
            glm::vec3 ks = obj->getKS() * glm::pow(glm::max(glm::dot(h, v), 0.0f), obj->getS());

            color += light->getIntensity() * (kd + ks);
        }

        return color;
    }
    return glm::vec3();
}

#include <iostream>
bool Scene::hit(glm::vec3 p, glm::vec3 v, float t0, float t1, std::shared_ptr<Shape>& obj, glm::vec3& hitPos,
                glm::vec3& hitNor)
{
    bool ret = false;
    float t = t1;
    for(std::shared_ptr<Shape> shape : shapes)
    {
        glm::vec3 pos;
        glm::vec3 nor;
        float s = shape->intersect(p, v, t0, t1, pos, nor);
        if(s < t)
        {
            t = s;
            obj = shape;
            hitPos = pos;
            hitNor = nor;
            ret = true;
        }
    }

    return ret;
}
