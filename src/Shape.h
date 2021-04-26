#ifndef _SHAPE_H_
#define _SHAPE_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shape
{
public:
    Shape();
    Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
          float _s);
    Shape(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
          float _s);
    Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
    ~Shape();

    bool isReflective() { return reflective; }
    glm::vec3 getPos() { return pos; }
    glm::vec3 getScale() { return scale; }
    glm::vec3 getRotation() { return rotation; }
    glm::vec3 getKA() { return ka; }
    glm::vec3 getKD() { return kd; }
    glm::vec3 getKS() { return ks; }
    float getS() { return s; }

    virtual float intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3& hitPos, glm::vec3& hitNor);

protected:
    glm::vec3 pos;
    glm::vec3 scale;
    glm::vec3 rotation;
    glm::vec3 kd;
    glm::vec3 ks;
    glm::vec3 ka;
    float s;
    bool reflective;
    bool infScale;
};

#endif