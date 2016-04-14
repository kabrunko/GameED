#include "Game.h"


Game::Game() : mainWindow(sf::VideoMode(800, 600), "EDGame", sf::Style::Close)
{
	mainWindow.setFramerateLimit(30);
	mainWindow.setVerticalSyncEnabled(false);
	currentState = State::menu;

	if (!tLayout.loadFromFile("Content/layout.png"))
		std::cout << "Erro ao carregar layout" << std::endl;
	else
	{ 
		sLayout.setTexture(tLayout);
		sLayout.setPosition(sf::Vector2f(0.f, 0.f));
	}

	block.load("1.png", 3, 388);
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time gameTime = sf::seconds(1.f / 60.f);

	initialize();

	while (mainWindow.isOpen())
	{
		eventHandler();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > gameTime)
		{
			timeSinceLastUpdate -= gameTime;
			eventHandler();
		}

		update(gameTime.asSeconds());
		draw();
	}
}

void Game::initialize()
{

}

void Game::eventHandler()
{
	sf::Event event;
	
	while (mainWindow.pollEvent(event))
	{
		if (currentState == State::menu)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mainWindow.close();
				break;
			}

			block.eventHandler(mainWindow, event);
		}

		if (currentState == State::playing)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mainWindow.close();
				break;
			}
		}
	}
}

void Game::update(float timeAsSeconds)
{
	if (currentState == State::menu)
	{
		block.update(timeAsSeconds, mainWindow);
	}

	if (currentState == State::playing)
	{

	}
}

void Game::draw()
{
	mainWindow.clear(sf::Color::Magenta);
	if (currentState == State::menu)
	{
		block.draw(mainWindow, sf::RenderStates::Default);
		mainWindow.draw(sLayout);
	}

	if (currentState == State::playing)
	{

	}
	mainWindow.display();
}