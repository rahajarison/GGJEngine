#include		<iostream>
#include		<GGJResourcesLoader.hpp>
#include		<GGJContext.hpp>
#include		"FadeAnim.hpp"

FadeAnim::FadeAnim(void) : Animation(3), _stepOne(true)
{
	if (GGJ::ResourcesLoader::loadImage("black_screen.png"))
		_sprite.SetImage(*(GGJ::ResourcesLoader::getImage("black_screen.png")));
	else
		std::cerr << "Impossible de charger le fondu" << std::endl;
}
FadeAnim::~FadeAnim(void)
{
}

void		FadeAnim::draw(sf::RenderWindow& window)
{
	window.SetView(window.GetDefaultView());
	window.Draw(_sprite);
	window.SetView(GGJ::Context::getSingleton().accessView());
}
void		FadeAnim::callbackUpdate(float sinceLastFrame)
{
	if (_stepOne)
	{
		_sprite.SetColor(sf::Color(255, 255, 255, 255 - (_cursor * 255 / _length)));
		if (_cursor >= _length / 2)
			_stepOne = false;
	}
	else
		_sprite.SetColor(sf::Color(255, 255, 255, _cursor * 255 / _length));
}