#include	<iostream>
#include	<GGJResourcesLoader.hpp>
#include	"Cell.hpp"

Cell::Cell(const std::string& filename, const std::string& filename2)
{
	sf::Image *		image;
	sf::Image *		image2;
	
	std::cout << "begin..." << std::endl;
	if (GGJ::ResourcesLoader::loadImage(filename), GGJ::ResourcesLoader::loadImage(filename2))
	{
		std::cout << "load..." << std::endl;
		image = GGJ::ResourcesLoader::getImage(filename);
		image2 = GGJ::ResourcesLoader::getImage(filename2);
		this->skin.SetImage(*image); 
		this->light.SetImage(*image); 
	}
}
Cell::Cell(const std::string& filename)
{
	sf::Image *		image;
	
	std::cout << "begin..." << std::endl;
	if (GGJ::ResourcesLoader::loadImage(filename))
	{
		std::cout << "load..." << std::endl;
		image = GGJ::ResourcesLoader::getImage(filename);
		this->skin.SetImage(*image); 
	}
}
Cell::~Cell(void)
{
	std::cout << "end..." << std::endl;
}

void Cell::update(void)
{
}

void Cell::draw(sf::RenderWindow& window)
{
	std::cout << "draw..." << std::endl;
	window.Draw(this->skin);
	window.Draw(this->light);
}

void Cell::call(Object& otherObject)
{
}