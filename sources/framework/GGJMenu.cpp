#include			<GGJMenu.hpp>
#include			<GGJResourcesLoader.hpp>

namespace			GGJ
{
Menu::Menu(void)
{
	if (ResourcesLoader::loadImage("home.png"))
	{
		sf::Image*	image = ResourcesLoader::getImage("home.png");
		_sprite.SetImage(*image);
	}
}
Menu::~Menu(void)
{
}
void			Menu::draw(sf::RenderWindow& window)
{
	window.Draw(_sprite);
}

};