#include "Object.h"

Object::Object(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, glm::vec3 kd, glm::vec3 ks, glm::vec3 ka, float s) :
               Shape(pos, scale, rotation, kd, ks, ka, s)
{
    // Find transformation matrix
    auto M = std::make_shared<MatrixStack>();
    M->translate(pos);
    M->rotate(rotation.x, 1, 0, 0);
    M->rotate(rotation.y, 0, 1, 0);
    M->rotate(rotation.z, 0, 0, 1);
    M->scale(scale);
    E = M->topMatrix();
    IE = glm::inverse(E);
    ITE = glm::transpose(IE);
}

Object::~Object() {}

float Object::intersect(glm::vec3 p, glm::vec3 v, float t0, float t1, glm::vec3 &hitPos, glm::vec3 &hitNor)
{
    // Find p prime and v prime
    glm::vec3 p_ = glm::vec3(IE * glm::vec4(p, 1.0f));
    glm::vec3 v_ = glm::normalize(glm::vec3(IE * glm::vec4(v, 0.0f)));

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
        glm::vec3 n1 = glm::normalize(glm::vec3(ITE * glm::vec4(x1_, 0.0f)));
        float ta = glm::distance(x1, p);
        if(glm::dot(v, x1 - p) < 0)
        {
            ta = -ta;
        }

        // Find second intersection
        float tb_ = (-b - (float)sqrt(d)) / (2.0f * a);
        glm::vec3 x2_ = p_ + (tb_ * v_);
        glm::vec3 x2 = glm::vec3(E * glm::vec4(x2_, 1.0f));
        glm::vec3 n2 = glm::normalize(glm::vec3(ITE * glm::vec4(x2_, 0.0f)));
        float tb = glm::distance(x2, p);
        if(glm::dot(v, x2 - p) < 0)
        {
            tb = -tb;
        }

        // Use smallest distance
        float triT;
        if(ta < tb)
        {
            hitPos = x1;
            hitNor = n1;
            ret = ta;
            triT = tb;
        }
        else
        {
            hitPos = x2;
            hitNor = n2;
            ret = tb;
            triT = ta;
        }

        // Check range
        if(ret > t1 || ret < t0)
        {
            ret = t1 + 1.0f;
        }
        else
        {
            for(std::shared_ptr<Triangle> tri : triangles)
            {
                glm::vec3 hPos;
                glm::vec3 hNor;
                float t = tri->intersect(p, v, t0, t1, hPos, hNor);
                if(t < triT)
                {
                    triT = t;
                    hitNor = hNor;
                    hitPos = hPos;
                }
            }
        }
    }

    return ret;
}

void Object::addTriangles(std::vector<float> &posBuf)
{
    for(size_t i = 0; i < posBuf.size(); i += 9)
    {
        std::shared_ptr<Triangle> tri = std::make_shared<Triangle>(glm::vec3(posBuf[i], posBuf[i+1], posBuf[i+2]),
                                                                   glm::vec3(posBuf[i+3], posBuf[i+4], posBuf[i+5]),
                                                                   glm::vec3(posBuf[i+6], posBuf[i+7], posBuf[i+8]),
                                                                   E
        );
        triangles.push_back(tri);
    }
}
