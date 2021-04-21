#ifndef _SPHERE_H_
#define _SPHERE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Sphere
{
public:
    Sphere(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
           float _s);
    ~Sphere();

private:
    glm::vec3 pos;
    glm::vec3 scale;
    glm::vec3 rotation;
    glm::vec3 kd;
    glm::vec3 ks;
    glm::vec3 ka;
    float s;
};

#endif