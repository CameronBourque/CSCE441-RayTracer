#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape
{
public:
    Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
          float _s);
    Shape(glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _kd, glm::vec3 _ks, glm::vec3 _ka,
          float _s);
    Shape(glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
    ~Shape();

private:
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