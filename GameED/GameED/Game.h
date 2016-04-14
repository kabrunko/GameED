#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include <iostream>
#include "movableSprite.h"
enum State { menu, playing };

class Game
{
public:
	Game();
	~Game();

	void run();
	void initialize();
	void eventHandler();
	void update(float);
	void draw();

private:
	sf::RenderWindow mainWindow;
	unsigned int windowWidth, windowHeight;
	State currentState;

	sf::Sprite sLayout;
	sf::Texture tLayout;

	movableSprite block;

};

