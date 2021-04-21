#include "Scene.h"

namespace Scene {
    void scene1() {
        Sphere red(glm::vec3(-0.5f, 1.0f, 1.0f),
                   glm::vec3(1.0f),
                   glm::vec3(0.0f),
                   glm::vec3(1.0f, 0.0f, 0.0f),
                   glm::vec3(1.0f, 1.0f, 0.5f),
                   glm::vec3(0.1f, 0.1f, 0.1f),
                   100.0f
        );

        Sphere green(glm::vec3(0.5f, -1.0f, -1.0f),
                     glm::vec3(1.0f),
                     glm::vec3(0.0f),
                     glm::vec3(0.0f, 1.0f, 0.0f),
                     glm::vec3(1.0f, 1.0f, 0.5f),
                     glm::vec3(0.1f, 0.1f, 0.1f),
                     100.0f
        );

        Sphere blue(glm::vec3(0.0f, 1.0f, 0.0f),
                    glm::vec3(1.0f),
                    glm::vec3(0.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(1.0f, 1.0f, 0.5f),
                    glm::vec3(0.1f, 0.1f, 0.1f),
                    100.0f
        );

        Light light(glm::vec3(-2.0f, 1.0f, 1.0f),
                    1.0f
        );

        // TODO: Generate scene 1 image
    }

    void scene2() {
        Sphere red(glm::vec3(-0.5f, 1.0f, 1.0f),
                   glm::vec3(1.0f),
                   glm::vec3(0.0f),
                   glm::vec3(1.0f, 0.0f, 0.0f),
                   glm::vec3(1.0f, 1.0f, 0.5f),
                   glm::vec3(0.1f, 0.1f, 0.1f),
                   100.0f
        );

        Sphere green(glm::vec3(0.5f, -1.0f, -1.0f),
                     glm::vec3(1.0f),
                     glm::vec3(0.0f),
                     glm::vec3(0.0f, 1.0f, 0.0f),
                     glm::vec3(1.0f, 1.0f, 0.5f),
                     glm::vec3(0.1f, 0.1f, 0.1f),
                     100.0f
        );

        Sphere blue(glm::vec3(0.0f, 1.0f, 0.0f),
                    glm::vec3(1.0f),
                    glm::vec3(0.0f),
                    glm::vec3(0.0f, 0.0f, 1.0f),
                    glm::vec3(1.0f, 1.0f, 0.5f),
                    glm::vec3(0.1f, 0.1f, 0.1f),
                    100.0f
        );

        Light light(glm::vec3(-2.0f, 1.0f, 1.0f),
                    1.0f
        );

        // TODO: Generate scene 2 image
    }

    //void Scene::scene3() {}

    //void Scene::scene4() {}

    //void Scene::scene5() {}

    //void Scene::scene6() {}

    //void Scene::scene7() {}

    //void Scene::scene8() {}
}
