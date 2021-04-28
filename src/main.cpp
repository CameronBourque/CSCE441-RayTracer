#include <iostream>
#include <string>
#include <memory>

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include "Camera.h"

// This allows you to skip the `std::` in front of C++ standard library
// functions. You can also say `using std::cout` to be more selective.
// You should never do this in a header file.
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 4) {
		cout << "Usage: A6 scene imageSize imageFilename" << endl;
		return 0;
	}

	int sceneNum = atoi(argv[1]);
	if(sceneNum < 1 || sceneNum > 8)
    {
	    cout << "Invalid scene number. Should be between 1-8." << endl;
	    return 0;
    }

	int imageSize = atoi(argv[2]);
	string imageFilename(argv[3]);

	Camera camera(glm::vec3(0.0f, 0.0f, 5.0f), M_PI / 4.0f, 1.0f);
    std::shared_ptr<Scene> scene = make_shared<Scene>(sceneNum);
    camera.generateScene(scene, 4.0f, imageSize, imageFilename);
	
	return 0;
}
