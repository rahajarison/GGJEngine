#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"ObjMusic.hpp"

const std::string ObjMusic::MUSIC_NAME = "Devolute1-.ogg";

ObjMusic::ObjMusic(void)
{
	if (GGJ::ResourcesLoader::loadMusic(MUSIC_NAME))
	{
		GGJ::ResourcesLoader::getMusic(MUSIC_NAME)->Play();
	}
}
ObjMusic::~ObjMusic(void)
{
}

void			ObjMusic::update(void)
{ 
}
void			ObjMusic::draw(sf::RenderWindow&)
{
}
void			ObjMusic::call(Object&)
{
}