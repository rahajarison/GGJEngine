#include		<iostream>
#include		<GGJContext.hpp>
#include		"Game.hpp"

void				mainCallback(void*)
{
	static unsigned int	i = 2;

	if (i == 0)
	{
		std::cin.ignore();
		GGJ::Context::getSingleton().stop();
	}
	else
	{
		std::cout << "Check !" << std::endl;
		--i;
	}
}
