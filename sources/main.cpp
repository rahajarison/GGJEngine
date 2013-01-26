#include	<cstdlib>
#include	<iostream>
#include	<GGJContext.hpp>
#include	"Game.hpp"
#include	"testJohnny.hpp"
#include	"engine/Character.h"
#include	"ObjDebug.hpp"
#include	"Cell.hpp"

void		registerAll(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	context.registerCallback(GGJ::registeringCallback(&Box2DCallback, 0));
	context.registerCallback(GGJ::registeringCallback(&mainCallback, 0));
}

void		initDebug(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();	
	b2Body*	body = context._world.m_world->GetBodyList();

	if (body)
	{
		// if (!Character::isCharacter(body))
			std::cout << "attachObject" << std::endl;
			context.attachObject(*(new ObjDebug(body)));
			std::cout << "fin attachObject" << std::endl;
		// else
			// context.attachObject(*(new Cell(body)));
	}
	while (body = body->GetNext())
	{
		// if (!Character::isCharacter(body))
			context.attachObject(*(new ObjDebug(body)));
		// else
			// context.attachObject(*(new Cell(body)));
	}
}

int			main(int ac, char *av[])
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	// std::cout << "Hey" << std::endl;
	// registerAll();
	// initDebug();
	// std::cout << "Salut" << std::endl;
	// context.run();
	return (EXIT_SUCCESS);
}