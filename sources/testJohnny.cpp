#include	<iostream>
#include	<GGJContext.hpp>
#include	"testJohnny.hpp"
#include	"objMusic.hpp"

void			test(void)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();
	ObjMusic*		music = new ObjMusic();

	context.attachObject(*music);
}