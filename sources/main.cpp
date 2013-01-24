#include	<cstdlib>
#include	<iostream>
#include	<GGJWindow.hpp>
#include	<GGJLog.hpp>

int			main(int ac, char *av[])
{
	GGJ::Window	window;
	GGJ::Log	log;

	log << "Test !" << GGJ::endl;
	std::cin.ignore();
	window.close();

	return (EXIT_SUCCESS);
}