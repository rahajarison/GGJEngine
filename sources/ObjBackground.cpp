#include		<iostream>
#include		<GGJContext.hpp>
#include		<GGJResourcesLoader.hpp>
#include		"ObjBackground.hpp"

ObjBackground::ObjBackground(void) : _speed(-1)
{
	if (GGJ::ResourcesLoader::loadImage("background_rose.png"))
	{
		this->_image = GGJ::ResourcesLoader::getImage("background_rose.png");
		_image->SetSmooth(false);
		this->_sprite.SetImage(*this->_image);
	}
	else
		std::cerr << "Impossible d afficher le background" << std::endl;
}
ObjBackground::~ObjBackground(void)
{
}

void		ObjBackground::update(void)
{
	GGJ::Context& context = GGJ::Context::getSingleton();

	this->_sprite.Move(context._world.car->bodies[0]->GetLinearVelocity().x * _speed * context.getFrameTime(), 0);
}
void		ObjBackground::draw(sf::RenderWindow& window)
{
	// _sprite loop qui se termine
	window.SetView(window.GetDefaultView());
	const sf::Vector2f position = _sprite.GetPosition();
	window.Draw(_sprite);
	for (unsigned int i = 0; i < 20; ++i)
	{
		_sprite.SetPosition(position.x + (_image->GetWidth() * i), position.y);
		window.Draw(_sprite);
	}
	_sprite.SetPosition(position);
	window.SetView(GGJ::Context::getSingleton().accessView());
}
void		ObjBackground::call(Object&)
{
}