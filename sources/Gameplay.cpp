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
	event.Key.Code = sf::Key::O;
	GGJ::registeringCallback callback(&OnFusionEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerDivide(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::P;
	GGJ::registeringCallback callback(&OnDivideEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerFront(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::W;
	GGJ::registeringCallback callback(&OnFrontEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerBack(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::S;
	GGJ::registeringCallback callback(&OnBackEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerLeft(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::A;
	GGJ::registeringCallback callback(&OnLeftEvent, &context);
	context.registerOnEvent(event, callback);
}
void		registerRight(void)
{
	sf::Event event;
	GGJ::Context&	context = GGJ::Context::getSingleton();

	event.Type = sf::Event::KeyPressed;
	event.Key.Code = sf::Key::D;
	GGJ::registeringCallback callback(&OnRightEvent, &context);
	context.registerOnEvent(event, callback);
}