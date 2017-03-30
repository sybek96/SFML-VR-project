#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm.hpp>
class Game
{
public:
	//Constructor
	Game(sf::ContextSettings settings);

	//Destructor
	~Game();

	//main game loop
	void run();
private:
	//enum of gamestates
	enum class GameState { SPLASH_SCREEN, TITLE_SCREEN, SPAWNING, PLAYING, OVER };

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
};

#endif