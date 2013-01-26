#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"ObjDebug.hpp"
#include	"engine/Define.h"

const unsigned int		ObjDebug::WIDTH = 40;
const unsigned int		ObjDebug::HEIGHT = 40;

ObjDebug::ObjDebug(b2Body* body) : _body(body),
_sprite(sf::Shape::Rectangle(0, 40, ObjDebug::WIDTH, ObjDebug::HEIGHT, sf::Color::Red))
{
	_sprite.SetCenter(WIDTH / 2, HEIGHT / 2);
	std::cout << "Creation"<< std::endl;
}
ObjDebug::~ObjDebug(void)
{
}

void			ObjDebug::update(void)
{ 
	const b2Vec2& vector = _body->GetPosition();
	_sprite.SetPosition(vector.x * COEF_DISPLAY, vector.y * COEF_DISPLAY);
}
void			ObjDebug::draw(sf::RenderWindow& window)
{ 
	window.Draw(_sprite);
}
void			ObjDebug::call(Object&) { }