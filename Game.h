#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include <Debug.h>
#include <iostream>
#include <fstream>
#include <string>



#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <memory>
#include "ImgData.h"
#include "MyCube.h"
#include "IDs.h"
#include "PlayerCam.h"

class Game
{
public:
	//Constructor
	Game(sf::ContextSettings settings);

	//Destructor
	~Game();

	//main game loop
	void run();

	//loading shader file
	std::string Game::loadShaderFile(std::string type, std::string contents);

	//Generte random x values
	float randNumX();

	//setting up array and buffer for objects
	void setUpArrayAndBuffer(IDs & ids, const GLuint & sizeBuffer, const GLuint & sizeIndex, const GLuint index[]);

	//setting up a shader
	void setUpShader(GLuint & id, const GLchar** src, const GLenum & type);

	//setting up the program to run on GPU
	void setUpProgram(GLuint & progID, const GLuint & vsid, const GLuint & fsid);
private:
	//enum of gamestates
	enum class GameState{ SPLASH_SCREEN, TITLE_SCREEN,SPAWNING,PLAYING,OVER};
	
	//the main game window
	sf::RenderWindow window;

	//clock of the game
	sf::Clock m_clock;

	//elapsed time
	sf::Time m_elapsed;

	//fps
	const sf::Time TIME_PER_UPDATE = sf::seconds(1 / 60.0f);

	//game is running bool
	bool isRunning = false;

	//initialise
	void initialize();

	//update
	void update(double);

	//render
	void render();

	//unload
	void unload();

	//cube texture image data
	ImgData m_texture;

	//road texture image data
	ImgData m_texture2;

	//contents of the vertex shader file
	std::string fileContentsVertex;

	//contents of the fragment shader file
	std::string fileContentsFragment;

	//vertex shader source code
	const char* vs_src;

	//fragment shader source code
	const char* fs_src;

	//cube ids
	IDs m_ids;

	//road ids
	IDs m_idsRoad;

	//view matrix
	glm::mat4 m_view;

	//unique pointer to the player cube
	std::unique_ptr<MyCube> m_playerCube;

	//A clear walls bool
	bool m_clearWalls;

	//screen center
	sf::Vector2f m_screenCenter;	

	PlayerCam m_playerCam;
};

#endif