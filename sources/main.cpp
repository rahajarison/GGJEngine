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
#include	"AudioManager.hpp"
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
	std::list<std::string> soundNames;
	std::list<std::string> musicNames;

	soundNames.push_back("absorption_nutrient.ogg");
	soundNames.push_back("bumper.ogg");
	soundNames.push_back("Divide.ogg");
	soundNames.push_back("heartbeat.ogg");
	soundNames.push_back("heartbeat_leo(level_ending).ogg");
	soundNames.push_back("Regroup.ogg");

	musicNames.push_back("Devolute1-.ogg");
	musicNames.push_back("music.ogg");

	AudioManager* audio_manager = new AudioManager(musicNames, soundNames, "Devolute1-.ogg");
	context.attachObject(*(new ObjBackground()));
	// context.accessView().Zoom(0.3f);
	// context.attachObject(*(new ObjPattern("bumper.png", 0, 0)));
	// loadLevelDesign();
	
	while (body != NULL)
	{
		if (!Character::isCharacter(body))
			context.attachObject(*(new ObjBumper(body)));
		else
		{
			context.attachObject(*(new ObjCell(body)));
			// switch ((long int)body->GetUserData())
			// {
			// }
		}
			
		// std::cout << "user data: " << (int) body->GetUserData() << std::endl;
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