#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#pragma once


namespace T
{
	class Game
	{
		sf::RenderWindow window;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::CircleShape code[5], rate[5];
		sf::Event event;
		sf::Font font;
		sf::Text text[5];
		sf::Color colorCode[5];
		size_t lives;
		bool victory;
		void decideCode();
		void display();
		void updateGame();
		static void cycleColor(sf::CircleShape&);
		void rateCode();
		bool win();
	public:
		explicit Game();
		virtual ~Game();
		void run();
	};
}