#include	<iostream>
#include	<string>
#include	<GGJContext.hpp>
#include	"testJohnny.hpp"
#include	"objMusic.hpp"
#include	"Cell.hpp"

void			test(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();
	ObjMusic*		music = new ObjMusic();

	context.attachObject(*music);
}

void			test(const std::string& filename)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();
	Cell*		cell = new Cell(filename);

	context.attachObject(*cell);
}