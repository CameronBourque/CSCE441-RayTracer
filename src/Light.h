#ifndef _LIGHT_H_
#define _LIGHT_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light
{
public:
    Light(glm::vec3 _pos, float _intensity);
    ~Light();

private:
    glm::vec3 pos;
    float intensity;
};

#endif