#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"ObjDebug.hpp"

ObjDebug::ObjDebug(b2Body* body) : _body(body)
{
}
ObjDebug::ObjDebug(void) : _sprite(sf::Shape::Rectangle(0, 40, 40, 40, sf::Color::Red))
{
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
	// Mise a jour de la position depuis context._world.m_world->GetBodyList();
	// GetPosition 	depuis le b2body
}
void			ObjDebug::draw(sf::RenderWindow& window)
{ 
	window.Draw(_sprite);
}
void			ObjDebug::call(Object&) { }