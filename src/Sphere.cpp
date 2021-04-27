#include "Sphere.h"

Sphere::Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
               Shape(pos, scale, rotation, kd, ks, ka, s)
{}

Sphere::Sphere(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation) :
        Shape(pos, scale, rotation)
{}

Sphere::~Sphere() {}

#include <iostream>
float Sphere::intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor)
{
    // Sphere collision (should include elipsoid collision)

    // Find transformation matrix
    auto M = std::make_shared<MatrixStack>();
    M->translate(pos);
    M->rotate(rotation.x, 1, 0, 0);
    M->rotate(rotation.y, 0, 1, 0);
    M->rotate(rotation.z, 0, 0, 1);
    M->scale(scale);
    glm::mat4 E = M->topMatrix();

    // Find p prime and v prime
    glm::vec3 p_ = glm::vec3(glm::inverse(E) * glm::vec4(p, 1.0f));
    glm::vec3 v_ = glm::normalize(glm::vec3(glm::inverse(E) * glm::vec4(v, 0.0f)));

    // Find a, b, c, d
    float a = glm::dot(v_, v_);
    float b = glm::dot(2.0f * v_, p_);
    float c = glm::dot(p_, p_) - 1.0f;
    float d = (b * b) - (4.0f * a * c);

    float ret = t1 + 1.0f;

    // See if intersects
    if(d > 0.0f)
    {
        // Find first intersection
        float ta_ = (-b + (float)sqrt(d)) / (2.0f * a);
        glm::vec3 x1_ = p_ + (ta_ * v_);
        glm::vec3 x1 = glm::vec3(E * glm::vec4(x1_, 1.0f));
        glm::vec3 n1 = glm::normalize(glm::vec3(glm::inverse(glm::transpose(E)) * glm::vec4(x1_, 0.0f)));
        float ta = glm::distance(x1, p);
        if(glm::dot(v, x1 - p) < 0)
        {
            ta = -ta;
        }

        // Find second intersection
        float tb_ = (-b - (float)sqrt(d)) / (2.0f * a);
        glm::vec3 x2_ = p_ + (tb_ * v_);
        glm::vec3 x2 = glm::vec3(E * glm::vec4(x2_, 1.0f));
        glm::vec3 n2 = glm::normalize(glm::vec3(glm::inverse(glm::transpose(E)) * glm::vec4(x2_, 0.0f)));
        float tb = glm::distance(x2, p);
        if(glm::dot(v, x2 - p) < 0)
        {
            tb = -tb;
        }

        // Use smallest distance
        if(ta < tb)
        {
            hitPos = x1;
            hitNor = n1;
            ret = ta;
        }
        else
        {
            hitPos = x2;
            hitNor = n2;
            ret = tb;
        }

        // Check range
        if(ret > t1 || ret < t0)
        {
            ret = t1 + 1.0f;
        }
    }

    return ret;
}
