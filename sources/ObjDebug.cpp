#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"ObjDebug.hpp"

const unsigned int		ObjDebug::WIDTH = 40;
const unsigned int		ObjDebug::HEIGHT = 40;

ObjDebug::ObjDebug(b2Body* body) : _body(body),
_sprite(sf::Shape::Rectangle(0, 40, ObjDebug::WIDTH, ObjDebug::HEIGHT, sf::Color::Red))
{
	_sprite.SetCenter(WIDTH / 2, HEIGHT / 2);
}
ObjDebug::~ObjDebug(void)
{
}

void			ObjDebug::applyToSprite(void)
{
	_sprite.SetX(this->_posX);
	_sprite.SetY(this->_posY);
}
void			ObjDebug::update(void)
{ 
	std::cout << "Update !" << std::endl;
	const b2Vec2& vector = _body->GetPosition();
	_sprite.SetPosition(vector.x, vector.y);
}
void			ObjDebug::draw(sf::RenderWindow& window)
{ 
	window.Draw(_sprite);
}
void			ObjDebug::call(Object&) { }