#include	<iostream>
#include	"Cell.hpp"
#include	<GGJResourcesLoader.hpp>

Cell::Cell(const std::string& filename) : Object()
{
	sf::Image *		image;
	
	std::cout << "a" << std::endl;
	if (GGJ::ResourcesLoader::loadImage(filename))
	{
		image = GGJ::ResourcesLoader::getImage(filename);
		this->skin.SetImage(*image); 
	}
	else
		std::cerr << "Failure image" << std::endl;
}
Cell::~Cell(void)
{
}

void Cell::update(void)
{
}

void Cell::draw(sf::RenderWindow& window)
{
	window.Draw(this->skin);
}

void Cell::call(Object& otherObject)
{
}