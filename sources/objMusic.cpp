#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"ObjMusic.hpp"

const std::string ObjMusic::MUSIC_NAME = "Devolute1-.ogg";

ObjMusic::ObjMusic(void)
{
	// std::cout << "begin" << std::endl;
	if (GGJ::ResourcesLoader::loadMusic(MUSIC_NAME))
	{
		// std::cout << "load" << std::endl;
		GGJ::ResourcesLoader::getMusic(MUSIC_NAME)->Play();
		// std::cout << "load end" << std::endl;
	}
}
ObjMusic::~ObjMusic(void)
{
	// std::cout << "end" << std::endl;
}

void			ObjMusic::update(void)
{ 
	// std::cout << "Update !" << std::endl;
}
void			ObjMusic::draw(sf::RenderWindow&)
{
}
void			ObjMusic::call(Object&)
{
}