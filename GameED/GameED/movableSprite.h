#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class movableSprite
{
	public:
		movableSprite();
		~movableSprite();

		void load(std::string filename, int x, int y);
		void eventHandler(sf::RenderWindow &, sf::Event &);
		void update(float, sf::RenderWindow &);
		void draw(sf::RenderTarget &, sf::RenderStates);

	private:
		std::string defaultLocation;
		sf::Texture _texture;
		sf::Sprite _sprite;

		sf::Vector2f _vector2f;
		sf::Vector2i _vector2i;

		bool mouseIsPressed;
};

