#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class PlayerCam
{
public:
	PlayerCam();
	~PlayerCam();
	void update();
	glm::mat4 getLeftEye();
	glm::mat4 getRightEye();
	glm::mat4 mvp, projection,
		view, model,
		mvp2, projection2,
		view2, model2;			// Model View Projection
};

