#include "Light.h"

Light::Light(glm::vec3 _pos, float _intensity) :
             pos(_pos),
             intensity(_intensity)
{}

Light::~Light() {}
