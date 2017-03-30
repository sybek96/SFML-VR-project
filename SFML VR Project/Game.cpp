#include "Game.h"


/// <summary>
/// Game constructor
/// </summary>
/// <param name="settings"></param>
Game::Game(sf::ContextSettings settings)
	: window(sf::VideoMode(800, 600),
		"SFML VR",
		sf::Style::Default,
		settings)
{

}

/// <summary>
/// game destructor
/// </summary>
Game::~Game() {}

/// <summary>
/// main game loop
/// </summary>
void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning)
	{
		m_elapsed += m_clock.restart();

#if (DEBUG >= 2)
		DEBUG_MSG("Game running...");
#endif

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}

		while (m_elapsed > TIME_PER_UPDATE)
		{
			m_elapsed -= TIME_PER_UPDATE;
			update(TIME_PER_UPDATE.asSeconds());
		}
		render();
	}
}

/// <summary>
/// Method to initialise the game
/// </summary>
void Game::initialize()
{
	isRunning = true;
}

/// <summary>
/// The update loop
/// </summary>
/// <param name="dt">time</param>
void Game::update(double dt)
{

}

/// <summary>
/// Render method for drawing to screen
/// </summary>
void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	window.display();
}

