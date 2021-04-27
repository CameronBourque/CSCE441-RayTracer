#include "Shape.h"

Shape::Shape() :
    pos(0.0f),
    scale(0.0f),
    rotation(0.0f),
    kd(0.0f),
    ks(0.0f),
    ka(0.0f),
    s(0.0f),
    reflective(false),
    infScale(false)
{}

Shape::Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
             float _s) :
             pos(_pos),
             scale(_scale),
             rotation(_rotation),
             kd(_kd),
             ks(_ks),
             ka(_ka),
             s(_s),
             reflective(false),
             infScale(false)
{}

Shape::Shape(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka, float _s) :
             pos(_pos),
             scale(glm::vec3(1.0f)),
             rotation(_rotation),
             kd(_kd),
             ks(_ks),
             ka(_ka),
             s(_s),
             reflective(false),
             infScale(true)
{}

Shape::Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation) :
             pos(_pos),
             scale(_scale),
             rotation(_rotation),
             kd(0.0f),
             ks(0.0f),
             ka(0.0f),
             s(0.0f),
             reflective(true),
             infScale(false)
{}

Shape::~Shape() {}

#include <iostream>
float Shape::intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor)
{
    // Implement basic plane intersection
    glm::vec3 n = rotation;
    float t = glm::dot(n, pos - p) / glm::dot(n, v);
    if(t > t0 && t < t1)
    {
        hitPos = p + (t * v);
        hitNor = n;
        return t;
    }
    return t1 + 1.0f;
}
