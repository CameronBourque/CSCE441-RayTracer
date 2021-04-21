#include "Sphere.h"

Sphere::Sphere(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
               float _s) :
               pos(_pos),
               scale(_scale),
               rotation(_rotation),
               kd(_kd),
               ks(_ks),
               ka(_ka),
               s(_s)
{}

Sphere::~Sphere() {}
