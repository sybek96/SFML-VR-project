#ifndef _IDs
#define _IDs
#include <GL\glew.h>

/// <summary>
/// A struct of ids
/// </summary>
struct IDs
{
	IDs()
		: m_vsid(0u)
		, m_fsid(0u)
		, m_progID(0u)
		, m_vao(0u)
		, m_vbo(0u)
		, m_vib(0u)
		, m_to(0u)
		, m_positionID(0u)
		, m_colorID(0u)
		, m_textureID(0u)
		, m_uvID(0u)
		, m_mvpID(0u)
	{}

	~IDs()
	{
		glDeleteProgram(m_progID);	//Delete Shader
		glDeleteBuffers(1, &m_vbo);	//Delete Vertex Buffer
		glDeleteBuffers(1, &m_vib);	//Delete Vertex Index Buffer
	}

	GLuint	m_vsid;		// Vertex Shader ID
	GLuint	m_fsid;		// Fragment Shader ID
	GLuint	m_progID;		// Program ID
	GLuint	m_vao;		// Vertex Array ID
	GLuint	m_vbo;		// Vertex Buffer ID
	GLuint	m_vib;		// Vertex Index Buffer
	GLuint	m_to;			// Texture ID 1 to 32
	GLuint	m_positionID;	// Position ID
	GLuint	m_colorID;	// Color ID
	GLuint	m_textureID;	// Texture ID
	GLuint	m_uvID;		// UV ID
	GLuint	m_mvpID;		// Model View Projection ID
};
#endif // !IDs