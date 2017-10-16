#include <iostream>
#include <exception>
#include "Game.h"


int main()
{
	try
	{
		T::Game game;
		game.run();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}