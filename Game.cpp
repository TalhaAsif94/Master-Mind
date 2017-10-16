#include <exception>
#include <cstdlib>
#include <ctime>
#include "Game.h"


///Private Functions
//Decides The Color Code
void T::Game::decideCode()
{
	size_t array[5];
	srand(static_cast <size_t> (time(0)));
	for (size_t i = 0; i < 5; i++)
		array[i] = rand() % 6;
	for (size_t i = 0; i < 5; i++)
	{
		switch (array[i])
		{
		case 0:
			colorCode[i] = sf::Color::Red;
			break;
		case 1:
			colorCode[i] = sf::Color::Yellow;
			break;
		case 2:
			colorCode[i] = sf::Color::Blue;
			break;
		case 3:
			colorCode[i] = sf::Color::Cyan;
			break;
		case 4:
			colorCode[i] = sf::Color::Green;
			break;
		default:
			colorCode[i] = sf::Color::Magenta;
			break;
		}
	}
}


//Displays The Window
void T::Game::display() { window.display(); }


//Updates The Window
void T::Game::updateGame()
{
	window.clear();
	window.draw(code[0]);
	window.draw(code[1]);
	window.draw(code[2]);
	window.draw(code[3]);
	window.draw(code[4]);
	window.draw(text[0]);
	window.draw(text[1]);
	window.draw(text[2]);
	switch (lives)
	{
	case 0:
		text[3].setString("0");
		break;
	case 1:
		text[3].setString("1");
		break;
	case 2:
		text[3].setString("2");
		break;
	case 3:
		text[3].setString("3");
		break;
	case 4:
		text[3].setString("4");
		break;
	case 5:
		text[3].setString("5");
		break;
	case 6:
		text[3].setString("6");
		break;
	case 7:
		text[3].setString("7");
		break;
	case 8:
		text[3].setString("8");
		break;
	case 9:
		text[3].setString("9");
		break;
	case 10:
		text[3].setString("10");
		break;
	case 11:
		text[3].setString("11");
		break;
	case 12:
		text[3].setString("12");
		break;
	case 13:
		text[3].setString("13");
		break;
	case 14:
		text[3].setString("14");
		break;
	case 15:
		text[3].setString("15");
		break;
	}
	window.draw(text[3]);
	if (lives != 15)
		window.draw(text[4]);
	if ((lives != 15 && lives != 0) && !victory)
	{
		window.draw(rate[0]);
		window.draw(rate[1]);
		window.draw(rate[2]);
		window.draw(rate[3]);
		window.draw(rate[4]);
	}
}


//Cycles The Color Of The Code
void T::Game::cycleColor(sf::CircleShape& circle)
{
	sf::Color color = circle.getFillColor();
	if (color == sf::Color::Red)
		circle.setFillColor(sf::Color::Yellow);
	else if (color == sf::Color::Yellow)
		circle.setFillColor(sf::Color::Blue);
	else if (color == sf::Color::Blue)
		circle.setFillColor(sf::Color::Cyan);
	else if (color == sf::Color::Cyan)
		circle.setFillColor(sf::Color::Green);
	else if (color == sf::Color::Green)
		circle.setFillColor(sf::Color::Magenta);
	else if (color == sf::Color::Magenta)
		circle.setFillColor(sf::Color::Red);
}


//Rates The Guess
void T::Game::rateCode()
{
	srand(static_cast <size_t> (time(0)));
	size_t array[5] = { 2, 2, 2, 2, 2 }, index[5] = { 2,2,2,2,2 }, num;


	if (colorCode[0] == code[0].getFillColor())
		array[0] = 1;
	if (colorCode[1] == code[1].getFillColor())
		array[1] = 1;
	if (colorCode[2] == code[2].getFillColor())
		array[2] = 1;
	if (colorCode[3] == code[3].getFillColor())
		array[3] = 1;
	if (colorCode[4] == code[4].getFillColor())
		array[4] = 1;
	for (size_t i = 0; i < 5; i++)
	{
		if (array[i] == 2)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (i == j)
					continue;
				else if (code[i].getFillColor() == colorCode[j])
					array[i] = 0;
			}
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		do
		{
			num = rand() % 5;
			if (index[num] == 2)
				break;
		} while (true);


		index[num] = 1;
		switch (array[i])
		{
		case 0:
			rate[num].setFillColor(sf::Color::White);
			break;
		case 1:
			rate[num].setFillColor(sf::Color::Red);
			break;
		default:
			rate[num].setFillColor(sf::Color::Black);
			break;
		}
	}
}


//Checks To See If The Code Is Guessed
bool T::Game::win()
{
	if (rate[0].getFillColor() == sf::Color::Red)
	{
		if (rate[1].getFillColor() == sf::Color::Red)
		{
			if (rate[2].getFillColor() == sf::Color::Red)
			{
				if (rate[3].getFillColor() == sf::Color::Red)
				{
					if (rate[4].getFillColor() == sf::Color::Red)
						return true;
				}
			}
		}
	}
	return false;
}


///Public Functions
//Initialisation
T::Game::Game() : lives(15), victory(false)
{
	window.create(sf::VideoMode(300, 300), "Master Mind!");
	code[0].setRadius(static_cast <float> (20));
	code[1].setRadius(static_cast <float> (20));
	code[2].setRadius(static_cast <float> (20));
	code[3].setRadius(static_cast <float> (20));
	code[4].setRadius(static_cast <float> (20));
	code[0].setFillColor(sf::Color::Red);
	code[1].setFillColor(sf::Color::Red);
	code[2].setFillColor(sf::Color::Red);
	code[3].setFillColor(sf::Color::Red);
	code[4].setFillColor(sf::Color::Red);
	code[0].setPosition(static_cast <float> (30), static_cast <float> (60));
	code[1].setPosition(static_cast <float> (80), static_cast <float> (60));
	code[2].setPosition(static_cast <float> (130), static_cast <float> (60));
	code[3].setPosition(static_cast <float> (180), static_cast <float> (60));
	code[4].setPosition(static_cast <float> (230), static_cast <float> (60));
	if (!font.loadFromFile("mytype.ttf"))
	{
		throw std::invalid_argument("ERROR! File Not Found\n");
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setFillColor(sf::Color::White);
	}
	text[0].setString("Lives: ");
	text[1].setString("Rate");
	text[1].setPosition(static_cast <float> (130), static_cast <float> (150));
	text[2].setString("Help");
	text[2].setPosition(static_cast <float> (130), static_cast <float> (200));
	text[3].setPosition(static_cast <float> (80), static_cast <float> (0));
	text[4].setString("Result: ");
	text[4].setPosition(static_cast <float> (0), static_cast <float> (250));
	rate[0].setRadius(static_cast <float> (10));
	rate[1].setRadius(static_cast <float> (10));
	rate[2].setRadius(static_cast <float> (10));
	rate[3].setRadius(static_cast <float> (10));
	rate[4].setRadius(static_cast <float> (10));
	rate[0].setPosition(static_cast <float> (100), static_cast <float> (255));
	rate[1].setPosition(static_cast <float> (130), static_cast <float> (255));
	rate[2].setPosition(static_cast <float> (160), static_cast <float> (255));
	rate[3].setPosition(static_cast <float> (190), static_cast <float> (255));
	rate[4].setPosition(static_cast <float> (220), static_cast <float> (255));
	decideCode();
}


//Termination
T::Game::~Game()
{
	window.close();
}


//Runs The Game
void T::Game::run()
{
	sf::FloatRect codeRect;
	do
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return;
			else if (lives != 0 && !victory)
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					//Checks To See Left Mouse Click Inside The First Circle
					codeRect = code[0].getLocalBounds();
					codeRect.left += 30;
					codeRect.top += 60;
					if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
						T::Game::cycleColor(code[0]);
					else
					{
						//Checks To See Left Mouse Click Inside The Second Circle
						codeRect = code[1].getLocalBounds();
						codeRect.left += 80;
						codeRect.top += 60;
						if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
							T::Game::cycleColor(code[1]);
						else
						{
							//Checks To See Left Mouse Click Inside The Third Circle
							codeRect = code[2].getLocalBounds();
							codeRect.left += 130;
							codeRect.top += 60;
							if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
								T::Game::cycleColor(code[2]);
							else
							{
								//Checks To See Left Mouse Click Inside The Fourth Circle
								codeRect = code[3].getLocalBounds();
								codeRect.left += 180;
								codeRect.top += 60;
								if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
									T::Game::cycleColor(code[3]);
								else
								{
									//Checks To See Left Mouse Click Inside The Fifth Circle
									codeRect = code[4].getLocalBounds();
									codeRect.left += 230;
									codeRect.top += 60;
									if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
										T::Game::cycleColor(code[4]);
									else
									{
										//Checks To See Left Mouse Click Inside Rate
										codeRect = text[1].getLocalBounds();
										codeRect.left += 130;
										codeRect.top += 150;
										if (codeRect.contains(static_cast <float> (event.mouseButton.x), static_cast <float> (event.mouseButton.y)))
										{
											rateCode();
											if (win())
											{
												victory = true;
												text[4].setString("You Won! Congratulations!");
												text[4].setFillColor(sf::Color::Red);
												break;
											}
											else
												lives--;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (lives == 0)
		{
			text[4].setString("You Lost! Sorry!");
			text[4].setFillColor(sf::Color::Cyan);
		}
		updateGame();
		display();
	} while (true);
}