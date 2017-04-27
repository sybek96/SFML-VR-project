#include "PlayerCam.h"



PlayerCam::PlayerCam()
{
	count = 0;
	moveUp = true;
	// Projection Matrix 
	projection = glm::perspective(
		45.0f,					// Field of View 45 degrees
		1.0f,			// Aspect ratio
		5.0f,					// Display Range Min : 0.1f unit
		100.0f					// Display Range Max : 100.0f unit
	);

	//projection2 matrix
	projection2 = glm::perspective(
		45.0f,					// Field of View 45 degrees
		1.0f,			// Aspect ratio
		5.0f,					// Display Range Min : 0.1f unit
		100.0f					// Display Range Max : 100.0f unit
	);
	// Camera Matrix
	view = glm::lookAt(
		glm::vec3(-4.0f, 0.0f, 10.0f),	// Camera (x,y,z), in World Space
		glm::vec3(0.0f, 0.0f, -10.5f),		// Camera looking at centre of cube
		glm::vec3(0.0f, 1.0f, 0.0f)		// 0.0f, 1.0f, 0.0f Look Down and 0.0f, -1.0f, 0.0f Look Up
	);
	// Camera2 Matrix
	view2 = glm::lookAt(
		glm::vec3(4.0f, 0.0f, 10.0f),	// Camera (x,y,z), in World Space
		glm::vec3(0.0f, 0.0f, -10.5f),		// Camera looking at centre of cube
		glm::vec3(0.0f, 1.0f, 0.0f)		// 0.0f, 1.0f, 0.0f Look Down and 0.0f, -1.0f, 0.0f Look Up
	);
	// Model matrix
	model = glm::mat4(
		1.0f					// Identity Matrix
	);
	// Model2 matrix
	model2 = glm::mat4(
		1.0f					// Identity Matrix
	);
}


PlayerCam::~PlayerCam()
{
}

void PlayerCam::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		view = rotate(view, -0.02f, glm::vec3(0, 1, 0)); // Rotate
		view2 = rotate(view2, -0.02f, glm::vec3(0, 1, 0)); // Rotate
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		view = rotate(view, 0.02f, glm::vec3(0, 1, 0)); // Rotate
		view2 = rotate(view2, 0.02f, glm::vec3(0, 1, 0)); // Rotate
	}

	if (count < 50 && moveUp)
	{
		count++;
		model = glm::translate(model, glm::vec3(0, 0.03, 0));
		model2 = glm::translate(model2, glm::vec3(0, 0.03, 0));
	}
	else if(count >= 1)
	{
		moveUp = false;
		count--;
		model = glm::translate(model, glm::vec3(0, -0.03, 0));
		model2 = glm::translate(model2, glm::vec3(0, -0.03, 0));
		if (count == 0)
		{
			moveUp = true;
		}
	}
	// Update Model View Projection
	// For mutiple objects (cubes) create multiple models
	// To alter Camera modify view & projection
	mvp = projection * view * model;
	mvp2 = projection2 * view2 * model2;
}

/// <summary>
/// Return mvp for left eye
/// </summary>
/// <returns></returns>
glm::mat4 PlayerCam::getLeftEye()
{
	return mvp;
}

/// <summary>
/// Return mvp for right eye
/// </summary>
/// <returns></returns>
glm::mat4 PlayerCam::getRightEye()
{
	return mvp2;
}
