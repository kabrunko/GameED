#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/******************************************************************
* Classe MovableSprite
* Objeto que representa basicamente uma imagem que pode ser movida
*******************************************************************/
class movableSprite
{
	public:
		movableSprite();					// Construtor
		~movableSprite();					// Destrutor

		void load(std::string filename, int x, int y);		// Carrega imagem em arquivo e atribui posição da imagem
		void eventHandler(sf::RenderWindow &, sf::Event &);	// Verifica eventos relacionados à imagem
		void update(float, sf::RenderWindow &);			// Atualiza posição da imagem
		void draw(sf::RenderTarget &, sf::RenderStates);	// Desenha imagem na janela

	private:
		std::string defaultLocation;				// Localização padrão das imagens
		sf::Texture _texture;					// Texture da imagem
		sf::Sprite _sprite;					// Sprite da imagem

		sf::Vector2f _vector2f;					// Posição float da imagem
		sf::Vector2i _vector2i;					// Posição int da imagem

		bool mouseIsPressed;					// Status do botão direito do mouse
};

