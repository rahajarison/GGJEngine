#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"objMusic.hpp"


ObjMusic::ObjMusic(void)
{
	if (GGJ::ResourcesLoader::loadMusic("music.ogg"))
	{
		std::cout << "Play music ?" << std::endl;
		GGJ::ResourcesLoader::getMusic("music.ogg")->Play();
	}
	else
		std::cerr << "Pas de musique" << std::endl;
}
ObjMusic::~ObjMusic(void)
{
}

void			ObjMusic::update(void)
{ 
	std::cout << "Update !" << std::endl;
}
void			ObjMusic::draw(sf::RenderWindow&)
{ }
void			ObjMusic::call(Object&) { }