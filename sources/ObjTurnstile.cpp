#include	<iostream>
#include	<GGJResourcesLoader.hpp>
#include	"ObjTurnstile.hpp"
#include	"engine/Define.h"

const std::string ObjTurnstile::IMAGE_NAME = "cellule.png";
const std::string ObjTurnstile::IMAGE2_NAME = "cellule_lueur.png";

ObjTurnstile::ObjTurnstile(b2Body* body) : _body(body)
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
	addTag(std::pair<std::string, std::string>("turnstile", "turnstile"));
}
ObjTurnstile::~ObjTurnstile(void)
{
	std::cout << "end..." << std::endl;
}

void ObjTurnstile::update(void)
{
	// std::cout << "update cell" << std::endl;
	const b2Vec2& vector = _body->GetPosition();
	skin.SetPosition(vector.x, vector.y);
	light.SetPosition(vector.x, vector.y);
}

void ObjTurnstile::draw(sf::RenderWindow& window)
{
	// std::cout << "Draw" << std::endl;
	window.Draw(this->skin);
	window.Draw(this->light);
}

void ObjTurnstile::call(Object& otherObject)
{
}