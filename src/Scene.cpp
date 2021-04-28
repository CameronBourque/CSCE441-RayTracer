#include "Scene.h"

#define _USE_MATH_DEFINES
#include <cmath>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

Scene::Scene(int _scene) :
             scene(_scene),
             epsilon(0.0001f),
             reflectLimit(6)
{
    std::shared_ptr<Shape> redSphere;
    std::shared_ptr<Shape> greenSphere;
    std::shared_ptr<Shape> blueSphere;
    std::shared_ptr<Shape> refSphere1;
    std::shared_ptr<Shape> refSphere2;
    std::shared_ptr<Shape> floor;
    std::shared_ptr<Shape> wall;
    std::shared_ptr<Shape> object;
    std::string objFile = "../resources/bunny.obj";

    std::shared_ptr<Light> light1;
    std::shared_ptr<Light> light2;

    switch (scene)
    {
        case 1:
        case 2:
        case 8:
            redSphere = std::make_shared<Sphere>(glm::vec3(-0.5f, -1.0f, 1.0f),
                                                 glm::vec3(1.0f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            greenSphere = std::make_shared<Sphere>(glm::vec3(0.5f, -1.0f, -1.0f),
                                                   glm::vec3(1.0f),
                                                   glm::vec3(0.0f),
                                                   glm::vec3(0.0f, 1.0f, 0.0f),
                                                   glm::vec3(1.0f, 1.0f, 0.5f),
                                                   glm::vec3(0.1f, 0.1f, 0.1f),
                                                   100.0f
            );
            shapes.push_back(greenSphere);

            blueSphere = std::make_shared<Sphere>(glm::vec3(0.0f, 1.0f, 0.0f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f),
                                                  glm::vec3(0.0f, 0.0f, 1.0f),
                                                  glm::vec3(1.0f, 1.0f, 0.5f),
                                                  glm::vec3(0.1f, 0.1f, 0.1f),
                                                  100.0f
            );
            shapes.push_back(blueSphere);

            light1 = std::make_shared<Light>(glm::vec3(-2.0f, 1.0f, 1.0f),
                                             1.0f
            );
            lights.push_back(light1);

            break;

        case 3:
            redSphere = std::make_shared<Sphere>(glm::vec3(0.5f, 0.0f, 0.5f),
                                                 glm::vec3(0.5f, 0.6f, 0.2f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            greenSphere = std::make_shared<Sphere>(glm::vec3(-0.5f, 0.0f, -0.5f),
                                                   glm::vec3(1.0f),
                                                   glm::vec3(0.0f),
                                                   glm::vec3(0.0f, 1.0f, 0.0f),
                                                   glm::vec3(1.0f, 1.0f, 0.5f),
                                                   glm::vec3(0.1f, 0.1f, 0.1f),
                                                   100.0f
            );
            shapes.push_back(greenSphere);

            floor = std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f),
                                            glm::vec3(0.0f, 1.0f, 0.0f),
                                            glm::vec3(1.0f, 1.0f, 1.0f),
                                            glm::vec3(0.0f, 0.0f, 0.0f),
                                            glm::vec3(0.1f, 0.1f, 0.1f),
                                            0.0f
            );
            shapes.push_back(floor);

            light1 = std::make_shared<Light>(glm::vec3(1.0f, 2.0f, 2.0f),
                                             0.5f
            );
            lights.push_back(light1);

            light2 = std::make_shared<Light>(glm::vec3(-1.0f, 2.0f, -1.0f),
                                             0.5f
            );
            lights.push_back(light2);

            break;

        case 4:
        case 5:
            redSphere = std::make_shared<Sphere>(glm::vec3(0.5f, -0.7f, 0.5f),
                                                 glm::vec3(0.3f),
                                                 glm::vec3(0.0f),
                                                 glm::vec3(1.0f, 0.0f, 0.0f),
                                                 glm::vec3(1.0f, 1.0f, 0.5f),
                                                 glm::vec3(0.1f, 0.1f, 0.1f),
                                                 100.0f
            );
            shapes.push_back(redSphere);

            blueSphere = std::make_shared<Sphere>(glm::vec3(1.0f, -0.7f, 0.0f),
                                                  glm::vec3(0.3f),
                                                  glm::vec3(0.0f),
                                                  glm::vec3(0.0f, 0.0f, 1.0f),
                                                  glm::vec3(1.0f, 1.0f, 0.5f),
                                                  glm::vec3(0.1f, 0.1f, 0.1f),
                                                  100.0f
            );
            shapes.push_back(blueSphere);

            floor = std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f),
                                            glm::vec3(0.0f, 1.0f, 0.0f),
                                            glm::vec3(1.0f, 1.0f, 1.0f),
                                            glm::vec3(0.0f, 0.0f, 0.0f),
                                            glm::vec3(0.1f, 0.1f, 0.1f),
                                            0.0f
            );
            shapes.push_back(floor);

            wall = std::make_shared<Plane>(glm::vec3(0.0f, 0.0f, -3.0f),
                                           glm::vec3(0.0f, 0.0f, 1.0f),
                                           glm::vec3(1.0f, 1.0f, 1.0f),
                                           glm::vec3(0.0f, 0.0f, 0.0f),
                                           glm::vec3(0.1f, 0.1f, 0.1f),
                                           0.0f
            );
            shapes.push_back(wall);

            refSphere1 = std::make_shared<Sphere>(glm::vec3(-0.5f, 0.0f, -0.5f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f)
            );
            shapes.push_back(refSphere1);

            refSphere2 = std::make_shared<Sphere>(glm::vec3(1.5f, 0.0f, -1.5f),
                                                  glm::vec3(1.0f),
                                                  glm::vec3(0.0f)
            );
            shapes.push_back(refSphere2);

            light1 = std::make_shared<Light>(glm::vec3(-1.0f, 2.0f, 1.0f),
                                             0.5f
            );
            lights.push_back(light1);

            light2 = std::make_shared<Light>(glm::vec3(0.5f, -0.5f, 0.0f),
                                             0.5f
            );
            lights.push_back(light2);
            break;

        case 6:
            object = std::make_shared<Object>(glm::vec3(0.0f, 0.0f, 0.0f),
                                              glm::vec3(0.0f, 0.0f, 0.0f),
                                              glm::vec3(1.0f),
                                              glm::vec3(0.0f, 0.0f, 1.0f),
                                              glm::vec3(1.0f, 1.0f, 0.5f),
                                              glm::vec3(0.1f, 0.1f, 0.1f),
                                              100.0f
            );
            getTrianglesFromObj(objFile, object);

            light1 = std::make_shared<Light>(glm::vec3(-1.0f, 1.0f, 1.0f),
                                             1.0f
            );
            lights.push_back(light1);
            break;

        case 7:
            //TODO: Get triangles from shapes
            object = std::make_shared<Object>(glm::vec3(0.3f, -1.5f, 0.0f),
                                              glm::vec3(M_PI / 9.0f, 0.0f, 0.0f),
                                              glm::vec3(1.5f),
                                              glm::vec3(0.0f, 0.0f, 1.0f),
                                              glm::vec3(1.0f, 1.0f, 0.5f),
                                              glm::vec3(0.1f, 0.1f, 0.1f),
                                              100.0f
            );
            getTrianglesFromObj(objFile, object);

            light1 = std::make_shared<Light>(glm::vec3(-1.0f, 1.0f, 1.0f),
                                             1.0f
            );
            lights.push_back(light1);
            break;

        default:
            break;
    }
}

Scene::~Scene() {}

glm::vec3 Scene::computeColor(glm::vec3 p, glm::vec3 v, float t0, float t1, int count)
{
    // Initialize color here as background color
    glm::vec3 color(0.0f);

    // If too many recursive calls then return early
    if(count >= reflectLimit)
    {
        return color;
    }

    std::shared_ptr<Shape> obj;
    glm::vec3 hitPos(0.0f);
    glm::vec3 hitNor(0.0f);

    // See if ray collides with shape
    if(hit(p, v, t0, t1, obj, hitPos, hitNor))
    {
        // See if reflective object
        if(obj->isReflective())
        {
            color = computeColor(hitPos, glm::reflect(v, hitNor), epsilon, t1, count+1);
        }
        else
        {
            // Color starts as ambient color
            color = obj->getKA();

            // Find e and n
            glm::vec3 e = glm::normalize(p - hitPos);
            glm::vec3 n = glm::normalize(hitNor);

            // For every light
            for (std::shared_ptr<Light> light : lights)
            {
                // Find l and h vectors
                glm::vec3 l = glm::normalize(light->getPos() - hitPos);
                glm::vec3 h = glm::normalize(l + e);

                // Throw away variables (don't want to overwrite what we have now)
                std::shared_ptr<Shape> temp;
                glm::vec3 hitPTemp;
                glm::vec3 hitNTemp;

                // Check if there's a shadow
                if (!hit(hitPos, l, epsilon, glm::length(light->getPos() - hitPos), temp, hitPTemp, hitNTemp))
                {
                    // Compute diffuse and specular for light
                    glm::vec3 diffuse = obj->getKD() * glm::max(glm::dot(l, n), 0.0f);
                    glm::vec3 specular = obj->getKS() *
                                         glm::pow(glm::max(glm::dot(h, n), 0.0f), obj->getS());

                    color += light->getIntensity() * (diffuse + specular);
                }
            }
        }
    }
    return color;
}

bool Scene::hit(glm::vec3 p, glm::vec3 v, float t0, float t1, std::shared_ptr<Shape>& obj, glm::vec3& hitPos,
                glm::vec3& hitNor)
{
    bool ret = false;
    float t = t1;
    for(std::shared_ptr<Shape> shape : shapes)
    {
        glm::vec3 pos;
        glm::vec3 nor;

        // Get the intersection distance
        float s = shape->intersect(p, v, t0, t1, pos, nor);

        // See if the distance is the smallest
        if(s < t && s > t0)
        {
            // Get record of stuff for later computation
            t = s;
            obj = shape;
            hitPos = pos;
            hitNor = nor;
            ret = true;
        }
    }

    return ret;
}

void Scene::getTrianglesFromObj(std::string& meshName, std::shared_ptr<Shape>& obj)
{
    // Load geometry
    std::vector<float> posBuf; // list of vertex positions
    std::vector<float> norBuf; // list of vertex normals
    std::vector<float> texBuf; // list of vertex texture coords
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string errStr;
    bool rc = tinyobj::LoadObj(&attrib, &shapes, &materials, &errStr, meshName.c_str());
    if(rc)
    {
        // Some OBJ files have different indices for vertex positions, normals,
        // and texture coordinates. For example, a cube corner vertex may have
        // three different normals. Here, we are going to duplicate all such
        // vertices.
        // Loop over shapes
        for (size_t s = 0; s < shapes.size(); s++) {
            // Loop over faces (polygons)
            size_t index_offset = 0;
            for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
                size_t fv = shapes[s].mesh.num_face_vertices[f];
                // Loop over vertices in the face.
                for (size_t v = 0; v < fv; v++) {
                    // access to vertex
                    tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                    posBuf.push_back(attrib.vertices[3 * idx.vertex_index + 0]);
                    posBuf.push_back(attrib.vertices[3 * idx.vertex_index + 1]);
                    posBuf.push_back(attrib.vertices[3 * idx.vertex_index + 2]);
                    if (!attrib.normals.empty()) {
                        norBuf.push_back(attrib.normals[3 * idx.normal_index + 0]);
                        norBuf.push_back(attrib.normals[3 * idx.normal_index + 1]);
                        norBuf.push_back(attrib.normals[3 * idx.normal_index + 2]);
                    }
                    if (!attrib.texcoords.empty()) {
                        texBuf.push_back(attrib.texcoords[2 * idx.texcoord_index + 0]);
                        texBuf.push_back(attrib.texcoords[2 * idx.texcoord_index + 1]);
                    }
                }
                index_offset += fv;
                // per-face material (IGNORE)
                shapes[s].mesh.material_ids[f];
            }
        }

        obj->addTriangles(posBuf);
    }
}
