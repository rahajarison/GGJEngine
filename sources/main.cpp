#include	<cstdlib>
#include	<iostream>
#include	<GGJContext.hpp>
#include	"engine/World.h"
#include	"Game.hpp"
#include	"testJohnny.hpp"
#include	"engine/Character.h"
#include	"ObjDebug.hpp"
#include	"ObjCell.hpp"
#include	"ObjBumper.hpp"
#include	"Gameplay.hpp"
#include	"ObjMusic.hpp"
#include	"ObjPattern.hpp"
#include	"ObjBackground.hpp"

void		registerAll(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	context.registerCallback(GGJ::registeringCallback(&Box2DCallback, 0));
	context.registerCallback(GGJ::registeringCallback(&mainCallback, 0));
	context.registerCallback(GGJ::registeringCallback(&cameraCallback, &context));
	registerImpulse();
	registerDivide();
	registerFusion();

	// registerFront();
	// registerBack();
	// registerLeft();
	// registerRight();
}

// void		loadLevelDesign(void)
// {
	
// }
void		initDebug(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();	
	b2Body*	body = context._world.m_world->GetBodyList();

	context.attachObject(*(new ObjMusic()));
	context.attachObject(*(new ObjBackground()));
	// context.accessView().Zoom(0.3f);
	// context.attachObject(*(new ObjPattern("bumper.png", 0, 0)));
	// loadLevelDesign();
	
	while (body != NULL)
	{
		if (!Character::isCharacter(body))
			context.attachObject(*(new ObjBumper(body)));
		else
			context.attachObject(*(new ObjCell(body)));
		std::cout << "user data: " << (int) body->GetUserData() << std::endl;
		body = body->GetNext();
	}
}

int			main(int ac, char *av[])
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	registerAll();
	initDebug();
	context.run();
	return (EXIT_SUCCESS);
}