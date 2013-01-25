#include	<cstdlib>
#include	<iostream>
#include	<GGJContext.hpp>
#include	"Game.hpp"

int			main(int ac, char *av[])
{
	GGJ::Context&	context = GGJ::Context::getSingleton();
	// sf::RenderWindow		window(sf::VideoMode(800, 800, 32), "Growing Leo");

	// window.Clear();
	// window.Display();
	// std::cin.ignore();
	// window.Close();
	context.registerCallback(GGJ::registeringCallback(&mainCallback, 0));
	context.run();
	return (EXIT_SUCCESS);
}