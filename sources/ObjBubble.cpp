#include	<iostream>
#include	<GGJResourcesLoader.hpp>
#include	"ObjBubble.hpp"
#include	"engine/Define.h"

const std::string ObjBubble::IMAGE_NAME = "bulle.png";
const std::string ObjBubble::IMAGE2_NAME = "cellule_lueur.png";

ObjBubble::ObjBubble(b2Body* body) : _body(body)
{
	sf::Image *		image;
	sf::Image *		image2;
	
	std::cout << "begin..." << std::endl;
	if (GGJ::ResourcesLoader::loadImage(IMAGE_NAME) && GGJ::ResourcesLoader::loadImage(IMAGE2_NAME))
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
	addTag(std::pair<std::string, std::string>("bubble", "bubble"));
}
ObjBubble::~ObjBubble(void)
{
	std::cout << "end..." << std::endl;
}

void ObjBubble::update(void)
{
	// std::cout << "update cell" << std::endl;
	const b2Vec2& vector = _body->GetPosition();
	skin.SetPosition(vector.x * COEF_DISPLAY, vector.y * COEF_DISPLAY);
	light.SetPosition(vector.x * COEF_DISPLAY, vector.y * COEF_DISPLAY);
}

void ObjBubble::draw(sf::RenderWindow& window)
{
	// std::cout << "Draw" << std::endl;
	window.Draw(this->skin);
	window.Draw(this->light);
}

void ObjBubble::call(Object& otherObject)
{
}