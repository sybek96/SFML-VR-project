#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>
#include "ImgData.h"
#include "IDs.h"

class MyCube
{
public:
	//Constructor
	MyCube(const glm::mat4 & view);

	//Overloaded constructor
	MyCube(float, float, float, const glm::mat4 &);
	~MyCube();
	virtual void update(double);
	virtual void render(const IDs & ids, glm::mat4 leftEyeMvp, glm::mat4 rightEyeMvp);
	//bool getActive() const;

	static const int VERTICES = 24;	// Total Number of Vertices
	static const int INDICES = 12;	// Total Number of Indexes
	static const int UVS = 48;	// Total Number of UVs
	static const int COLORS = 24;	// Total Number of Colors
	static const GLuint s_INDICES[36]; //indices total

protected:

	//Matrix view projection
	glm::mat4 mvp;

	//projection matrix
	glm::mat4 projection;

	//the reference to view matrix
	const glm::mat4 & m_view;

	// Model View Projection
	glm::mat4 model;	

	//vertices
	GLfloat m_vertices[72];

	//x offset
	float m_xOffset;

	//y offset
	float m_yOffset;

	//z offset
	float m_zOffset;

	//top right cube position
	sf::Vector3f m_positionTopRight;

	//top left cube position
	sf::Vector3f m_positionTopLeft;

};

