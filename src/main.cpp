#include <iostream>
#include <string>
#include <memory>

#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	int scene = atoi(argv[1]);
	int imageSize = atoi(argv[2]);
	string imageFilename(argv[3]);

	Camera camera(glm::vec3(0.0f, 0.0f, 5.0f), M_PI / 4.0f, 1.0f);
    camera.generateRays(4.0f, (float)imageSize, (float)imageSize);

    switch (scene) {
        case 1:
            break;
        default:
            break;
    }
	
	return 0;
}
