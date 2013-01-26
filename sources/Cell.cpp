#include	<iostream>
#include	<GGJResourcesLoader.hpp>
#include	"Cell.hpp"

const std::string Cell::IMAGE_NAME = "cellule.png";
const std::string Cell::IMAGE2_NAME = "cellule_light.png";

Cell::Cell(b2Body* body) : _body(body)
{
	sf::Image *		image;
	sf::Image *		image2;
	
	std::cout << "begin..." << std::endl;
	if (GGJ::ResourcesLoader::loadImage(IMAGE_NAME), GGJ::ResourcesLoader::loadImage(IMAGE2_NAME))
	{
		std::cout << "load..." << std::endl;
		image = GGJ::ResourcesLoader::getImage(IMAGE_NAME);
		image2 = GGJ::ResourcesLoader::getImage(IMAGE2_NAME);
		this->skin.SetImage(*image); 
		this->light.SetImage(*image); 
	}
}
// Cell::Cell(const std::string& filename)
// {
// 	sf::Image *		image;
	
// 	std::cout << "begin..." << std::endl;
// 	if (GGJ::ResourcesLoader::loadImage(filename))
// 	{
// 		std::cout << "load..." << std::endl;
// 		image = GGJ::ResourcesLoader::getImage(filename);
// 		this->skin.SetImage(*image); 
// 	}
// }
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