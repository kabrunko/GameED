#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include <iostream>
#include "movableSprite.h"
enum State { menu, playing };

// Classe Game
class Game
{
public:
	Game();
	~Game();

	void run();					// Loop principal do jogo
	void initialize();				// Inicializa recursos secundários
	void eventHandler();				// Gerenciador de eventos
	void update(float);				// Atualiza conteúdo do jogo
	void draw();					// Exibe conteúdo na janela

private:
	sf::RenderWindow mainWindow;			// Janela
	unsigned int windowWidth, windowHeight;		// Largura e altura da janela
	State currentState;				// Estado atual do jogo

	sf::Sprite sLayout;
	sf::Texture tLayout;

	movableSprite block;

};

