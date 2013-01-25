#include	<cstdlib>
#include	<iostream>
#include	<GGJContext.hpp>

int			main(int ac, char *av[])
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	context.run();
	return (EXIT_SUCCESS);
}