#include	<iostream>
#include	<GGJResourcesLoader.hpp>
#include	"engine/Define.h"
#include	"ObjCell.hpp"

const std::string ObjCell::IMAGE_NAME = "cellule.png";
const std::string ObjCell::IMAGE2_NAME = "cellule_lueur.png";

ObjCell::ObjCell(b2Body* body) : _body(body)
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
		this->light.SetImage(*image2);
		this->skin.SetCenter(image->GetWidth() / 2, image->GetHeight() / 2);
		this->light.SetCenter(image2->GetWidth() / 2, image2->GetHeight() / 2);
		std::cout << "Fin Load" << std::endl;
	}
	addTag(std::pair<std::string, std::string>("cell", "cell"));
}
ObjCell::~ObjCell(void)
{
	std::cout << "end..." << std::endl;
}

void ObjCell::update(void)
{
	// std::cout << "update cell" << std::endl;
	const b2Vec2& vector = _body->GetPosition();
	skin.SetPosition(vector.x, vector.y);
	light.SetPosition(vector.x, vector.y);

	float angle = _body->GetAngle() * RADTODEG;
	std::cout << _body->GetAngle() <<std::endl;
	skin.SetRotation(angle);
	light.SetRotation(angle);
}

void ObjCell::draw(sf::RenderWindow& window)
{
	// std::cout << "Draw" << std::endl;
	window.Draw(this->skin);
	window.Draw(this->light);
}

void ObjCell::call(Object& otherObject)
{
}