#include	<iostream>
#include	<GGJContext.hpp>
#include	"engine/World.h"
#include	"Game.hpp"
#include	"engine/Character.h"
#include	"ObjDebug.hpp"
#include	"ObjCell.hpp"
#include	"Gameplay.hpp"

void		registerImpulse(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::I;
	GGJ::registeringCallback callback(&OnImpulseEvent, &context);
	context.registerOnEvent(event, callback);	
}
void		registerFusion(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::F;
	GGJ::registeringCallback callback(&OnFusionEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerDivide(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::D;
	GGJ::registeringCallback callback(&OnDivideEvent, &context);
	context.registerOnEvent(event, callback);
}