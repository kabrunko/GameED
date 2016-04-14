#include "movableSprite.h"

// Construtor
movableSprite::movableSprite()
{
	defaultLocation = "Content/";
	mouseIsPressed = false;
}

// Destrutor
movableSprite::~movableSprite()
{
}

// Carrega imagem a partir de arquivo e seta posição da imagem
void movableSprite::load(std::string filename, int x, int y)
{
	_texture.loadFromFile(defaultLocation + filename);
	_sprite.setTexture(_texture);
	_sprite.setPosition(x, y);
}

// Verifica eventos relacionados à imagem
void movableSprite::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mouseIsPressed = true;
				std::cout << "Left mouse button PRESSED\n\n";
			}
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mouseIsPressed = false;
				std::cout << "Left mouse button RELEASED\n\n";
			}
			break;
	}
}

// Atualiza posições da imagem
void movableSprite::update(float timeAsSeconds, sf::RenderWindow& window)
{
	sf::Mouse mouse;

	if (mouse.getPosition(window).x > _sprite.getPosition().x && mouse.getPosition(window).y > _sprite.getPosition().y)
	{
		if (mouse.getPosition(window).x < _sprite.getPosition().x + _texture.getSize().x && 
			mouse.getPosition(window).y < _sprite.getPosition().y + _texture.getSize().y)
		{
			if (mouseIsPressed)
			{
				_sprite.setPosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
			}

			std::cout << "Mouse instersects!" << std::endl;
		}
	}
}

// Desenha conteúdo na janela
void movableSprite::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default)
{
	target.draw(_sprite);
}
