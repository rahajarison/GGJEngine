#include		<iostream>
#include		<GGJContext.hpp>
#include		"Game.hpp"

void				Box2DCallback(void*)
{
  // float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
  // int32 velocityIterations = 8;   //how strongly to correct velocity
  // int32 positionIterations = 3;   //how strongly to correct position
  
  // myWorld->Step( timeStep, velocityIterations, positionIterations);
}

void				mainCallback(void*)
{
	static unsigned int	i = 2;

	if (i == 0)
	{
		std::cin.ignore();
		GGJ::Context::getSingleton().stop();
	}
	else
	{
		std::cout << "Check !" << std::endl;
		--i;
	}
}
