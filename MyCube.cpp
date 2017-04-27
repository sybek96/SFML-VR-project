#include "MyCube.h"

// Source file
const GLuint MyCube::s_INDICES[] = 

{
	// Front Face
	0, 1, 2,
	2, 3, 0,

	// Top Face
	4, 5, 6,
	6, 7, 4,

	// Back Face
	8, 9, 10,
	10, 11, 8,

	// Bottom Face
	12, 13, 14,
	14, 15, 12,

	// Left Face
	16, 17, 18,
	18, 19, 16,

	// Right Face
	20, 21, 22,
	22, 23, 20
};

static GLfloat vertices[] =
{
	// Front Face
	-1.00f, -1.00f,  -10.00f,	// [0]	// ( 0)
	 1.00f, -1.00f,  -10.00f,	// [1]	// ( 1)
	 1.00f,  1.00f,  -10.00f,	// [2]	// ( 2)
	-1.00f,  1.00f,  -10.00f,	// [3]	// ( 3)

	// Top Face
	-1.00f,  1.00f,  -10.00f,	// [3]	// ( 4)
	 1.00f,  1.00f,  -10.00f,	// [2]	// ( 5)
	 1.00f,  1.00f, -11.00f,	// [6]	// ( 6)
	-1.00f,  1.00f, -11.00f,	// [7]	// ( 7)

	// Back Face
	 1.00f, -1.00f, -11.00f,	// [5]	// ( 8)
	-1.00f, -1.00f, -11.00f, // [4]	// ( 9)
	-1.00f,  1.00f, -11.00f,	// [7]	// (10)
	 1.00f,  1.00f, -11.00f,	// [6]	// (11)

	// Bottom Face
	-1.00f, -1.00f, -11.00f, // [4]	// (12)
	 1.00f, -1.00f, -11.00f, // [5]	// (13)
	 1.00f, -1.00f,  -10.00f, // [1]	// (14)
	-1.00f, -1.00f,  -10.00f, // [0]	// (15)

	// Left Face
	-1.00f, -1.00f, -11.00f, // [4]	// (16)
	-1.00f, -1.00f,  -10.00f, // [0]	// (17)
	-1.00f,  1.00f,  -10.00f, // [3]	// (18)
	-1.00f,  1.00f, -11.00f, // [7]	// (19)

	// Right Face
	 1.00f, -1.00f,  -10.00f, // [1]	// (20)
	 1.00f, -1.00f, -11.00f, // [5]	// (21)
	 1.00f,  1.00f, -11.00f, // [6]	// (22)
	 1.00f,  1.00f,  -10.00f, // [2]	// (23)
};

static const GLfloat colors[] = 
{
	
	// Front Face
	1.0f, 0.0f, 0.0f, 1.0f, // [0]	// ( 0)
	1.0f, 0.0f, 0.0f, 1.0f, // [1]	// ( 1)
	1.0f, 0.0f, 0.0f, 1.0f, // [2]	// ( 2)
	1.0f, 0.0f, 0.0f, 1.0f, // [3]	// ( 3)

	// Top Face
	0.0f, 1.0f, 0.0f, 1.0f, // [3]	// ( 4)
	0.0f, 1.0f, 0.0f, 1.0f, // [2]	// ( 5)
	0.0f, 1.0f, 0.0f, 1.0f, // [6]	// ( 6)
	0.0f, 1.0f, 0.0f, 1.0f, // [7]	// ( 7)

	// Back Face
	0.0f, 0.0f, 1.0f, 1.0f, // [5]	// ( 8)
	0.0f, 0.0f, 1.0f, 1.0f, // [4]	// ( 9)
	0.0f, 0.0f, 1.0f, 1.0f, // [7]	// (10)
	0.0f, 0.0f, 1.0f, 1.0f, // [6]	// (11)

	// Bottom Face
	0.0f, 1.0f, 1.0f, 1.0f, // [4]	// (12)
	0.0f, 1.0f, 1.0f, 1.0f, // [5]	// (13)
	0.0f, 1.0f, 1.0f, 1.0f, // [1]	// (14)
	0.0f, 1.0f, 1.0f, 1.0f, // [0]	// (15)

	// Left Face
	1.0f, 1.0f, 0.0f, 1.0f, // [4]	// (16)
	1.0f, 1.0f, 0.0f, 1.0f, // [0]	// (17)
	1.0f, 1.0f, 0.0f, 1.0f, // [3]	// (18)
	1.0f, 1.0f, 0.0f, 1.0f, // [7]	// (19)

	// Right Face
	1.0f, 0.0f, 1.0f, 1.0f, // [1]	// (20)
	1.0f, 0.0f, 1.0f, 1.0f, // [5]	// (21)
	1.0f, 0.0f, 1.0f, 1.0f, // [6]	// (22)
	1.0f, 0.0f, 1.0f, 1.0f, // [2]	// (23)
};

GLfloat uvs[2 * 4 * 6] = 
{
	// Front Face (other faces populated in initialisation) top left in this project 0,0
	0.33f, 0.66f, //tr
	0.0f, 0.66f, //tl
	0.0f, 0.33f, //bl
	0.33f, 0.33f, //br

	// Top Face
	0.33f, 0.33f,
	0.0f, 0.33f,
	0.0f, 0.0f,
	0.33f, 0.0f,


	//Back Face
	0.33f, 0.66f,
	0.0f, 0.66f,
	0.0f, 0.33f,
	0.33f, 0.33f,

	//Bottom Face
	0.33f, 1.0f,
	0.0f, 1.0f,
	0.0f, 0.66f,
	0.33f, 0.66f,

	//Left Face
	0.33f, 0.66f,
	0.0f, 0.66f,
	0.0f, 0.33f,
	0.33f, 0.33f,

	//Right Face
	0.33f, 0.66f,
	0.0f, 0.66f,
	0.0f, 0.33f,
	0.33f, 0.33f,
};

static const GLuint indices[] =
{
	// Front Face
	0, 1, 2,
	2, 3, 0,

	// Top Face
	4, 5, 6,
	6, 7, 4,

	// Back Face
	8, 9, 10,
	10, 11, 8,

	// Bottom Face
	12, 13, 14,
	14, 15, 12,

	// Left Face
	16, 17, 18,
	18, 19, 16,

	// Right Face
	20, 21, 22,
	22, 23, 20
};

/// <summary>
/// Default constructor
/// </summary>
/// <param name="view"></param>
MyCube::MyCube(const glm::mat4 & view)
	: m_view(view)
	, m_xOffset(0)
	, m_yOffset(0)
	, m_zOffset(0)
	//, m_active(true)
{
}

/// <summary>
/// overloaded constructor
/// </summary>
/// <param name="xOffset"></param>
/// <param name="yOffset"></param>
/// <param name="zOffset"></param>
/// <param name="view"></param>
MyCube::MyCube(float xOffset, float yOffset, float zOffset,const glm::mat4 & view) 
	: m_view(view)
	, m_xOffset(xOffset)
	, m_yOffset(yOffset)
	, m_zOffset(zOffset)
	//, m_active(true)
	, m_positionTopRight(xOffset + 1, yOffset + 1, zOffset + 1)
	, m_positionTopLeft(xOffset - 1, yOffset - 1, zOffset + 1)
{
	// Projection Matrix 
	projection = glm::perspective(
		45.0f,					// Field of View 45 degrees
		4.0f / 3.0f,			// Aspect ratio
		5.0f,					// Display Range Min : 0.1f unit
		100.0f					// Display Range Max : 100.0f unit
	);
	// Model matrix
	model = glm::mat4(
		1.0f					// Identity Matrix
	);
	model = glm::translate(model, glm::vec3(m_xOffset, m_yOffset, m_zOffset));
}

/// <summary>
/// destructor
/// </summary>
MyCube::~MyCube()
{
}

/// <summary>
/// update
/// </summary>
/// <param name="dt"></param>
void MyCube::update(double dt)
{
	mvp = projection * m_view * model;
}

/// <summary>
/// Render
/// </summary>
/// <param name="ids"></param>
void MyCube::render(const IDs & ids, glm::mat4 leftEyeMvp, glm::mat4 rightEyeMvp)
{
	//the left eye viewport
	glViewport(0, 0, 400, 400);
	// Rebind Buffers and then set SubData
	glBindBuffer(GL_ARRAY_BUFFER, ids.m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ids.m_vib);

	glUseProgram(ids.m_progID);
	//VBO Data....vertices, colors and UV's appended
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * VERTICES * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, 3 * VERTICES * sizeof(GLfloat), 4 * COLORS * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat), 2 * UVS * sizeof(GLfloat), uvs);

	// Send transformation to shader mvp uniform
	glUniformMatrix4fv(ids.m_mvpID, 1, GL_FALSE, &leftEyeMvp[0][0]);
	//Set Active Texture .... 32
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(ids.m_textureID, 0);

	//Set pointers for each parameter (with appropriate starting positions)
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glVertexAttribPointer.xml
	glVertexAttribPointer(ids.m_positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(ids.m_colorID, 4, GL_FLOAT, GL_FALSE, 0, (VOID*)(3 * VERTICES * sizeof(GLfloat)));
	glVertexAttribPointer(ids.m_uvID, 2, GL_FLOAT, GL_FALSE, 0, (VOID*)(((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat)));

	//Enable Arrays
	glEnableVertexAttribArray(ids.m_positionID);
	glEnableVertexAttribArray(ids.m_colorID);
	glEnableVertexAttribArray(ids.m_uvID);

	//Draw Element Arrays
	glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, NULL);

	//Disable Arrays
	glDisableVertexAttribArray(ids.m_positionID);
	glDisableVertexAttribArray(ids.m_colorID);
	glDisableVertexAttribArray(ids.m_uvID);

	// Unbind Buffers (Resets OpenGL States...important step)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//the right eye viewport
	glViewport(400, 0, 400, 400);
	// Rebind Buffers and then set SubData
	glBindBuffer(GL_ARRAY_BUFFER, ids.m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ids.m_vib);

	glUseProgram(ids.m_progID);
	//VBO Data....vertices, colors and UV's appended
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * VERTICES * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, 3 * VERTICES * sizeof(GLfloat), 4 * COLORS * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat), 2 * UVS * sizeof(GLfloat), uvs);

	// Send transformation to shader mvp uniform
	glUniformMatrix4fv(ids.m_mvpID, 1, GL_FALSE, &rightEyeMvp[0][0]);
	//Set Active Texture .... 32
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(ids.m_textureID, 0);

	//Set pointers for each parameter (with appropriate starting positions)
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glVertexAttribPointer.xml
	glVertexAttribPointer(ids.m_positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(ids.m_colorID, 4, GL_FLOAT, GL_FALSE, 0, (VOID*)(3 * VERTICES * sizeof(GLfloat)));
	glVertexAttribPointer(ids.m_uvID, 2, GL_FLOAT, GL_FALSE, 0, (VOID*)(((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat)));

	//Enable Arrays
	glEnableVertexAttribArray(ids.m_positionID);
	glEnableVertexAttribArray(ids.m_colorID);
	glEnableVertexAttribArray(ids.m_uvID);

	//Draw Element Arrays
	glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, NULL);

	//Disable Arrays
	glDisableVertexAttribArray(ids.m_positionID);
	glDisableVertexAttribArray(ids.m_colorID);
	glDisableVertexAttribArray(ids.m_uvID);

	// Unbind Buffers (Resets OpenGL States...important step)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

