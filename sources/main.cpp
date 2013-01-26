#include	<cstdlib>
#include	<iostream>
#include	<GGJContext.hpp>
#include	"Game.hpp"
#include	"testJohnny.hpp"
#include	"engine/Character.h"
#include	"ObjDebug.hpp"

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
		if (!Character::isCharacter(body))
			context.attachObject(*(new ObjDebug(body)));
	}
	while (body = body->GetNext())
	{
		if (!Character::isCharacter(body))
			context.attachObject(*(new ObjDebug()));
	}
}

int			main(int ac, char *av[])
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	registerAll();
	// test();
	// test("cellule.png");
	context.run();
	return (EXIT_SUCCESS);
}