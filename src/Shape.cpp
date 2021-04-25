#include "Shape.h"

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
             scale(_scale),
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

