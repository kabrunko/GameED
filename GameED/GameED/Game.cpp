/*****************************************
 * Game.cpp
 * Classe Game, possui o gameLoop do jogo
******************************************/
#include "Game.h"

// Construtor da classe Game
// Recebe por parâmetro sf::VideoMode com largura e altura da janela de jogo,
// uma string contendo o nome da janela e sf::Style o estilo da janela.
Game::Game() : mainWindow(sf::VideoMode(800, 600), "EDGame", sf::Style::Close)
{
	mainWindow.setFramerateLimit(30);				// Força a taxa de frames limite do jogo
	mainWindow.setVerticalSyncEnabled(false);			// Desativa a sincronização Vertical
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

// Destrutor da classe Game
Game::~Game()
{
}

// Loop principal do jogo
void Game::run()
{
	sf::Clock clock;						// Contador de tempo do jogo
	sf::Time timeSinceLastUpdate = sf::Time::Zero;			// Variável para tempo passado da ultima atualização
	sf::Time gameTime = sf::seconds(1.f / 30.f);			// Espaço de tempo entre atualizações 1/30 segundos (30fps)

	initialize();							

	while (mainWindow.isOpen())
	{
		eventHandler();						// Gerenciador de eventos
		timeSinceLastUpdate += clock.restart();			// Tempo desde a ultima atualização do jogo
		
		while (timeSinceLastUpdate > gameTime)			// Verifica se o tempo passado é superior a 1/30 segundos
		{
			timeSinceLastUpdate -= gameTime;		// Decrementa o tempo da atualização
			eventHandler();					// Gerenciador de eventos
		}

		update(gameTime.asSeconds());			
		draw();							
	}
}

// Inicializador de conteúdo secundário
void Game::initialize()
{

}

// Gerenciador de eventos
void Game::eventHandler()
{
	sf::Event event;
	
	while (mainWindow.pollEvent(event))
	{
		// Eventos verificados no menu do jogo
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
		
		// Eventos verificados durante a fase
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

// Atualiza conteúdo do jogo
void Game::update(float timeAsSeconds)
{
	// Atualização no menu
	if (currentState == State::menu)
	{
		block.update(timeAsSeconds, mainWindow);
	}

	// Atualização durante a fase
	if (currentState == State::playing)
	{

	}
}

// Exibe conteúdo na janela do jogo
void Game::draw()
{
	// Conteúdo a ser desenhado durante o menu
	mainWindow.clear(sf::Color::Magenta);
	if (currentState == State::menu)
	{
		block.draw(mainWindow, sf::RenderStates::Default);
		mainWindow.draw(sLayout);
	}

	// Conteúdo a ser desenhado durante a fase
	if (currentState == State::playing)
	{

	}
	mainWindow.display();
}
