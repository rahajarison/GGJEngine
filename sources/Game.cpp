#include		<iostream>
#include		<GGJContext.hpp>
#include		"Game.hpp"

void				Box2DCallback(void*)
{
  float32 timeStep = GGJ::Context::getFrameTime();      //the length of time passed to simulate (seconds)
  int32 velocityIterations = 8;   //how strongly to correct velocity
  int32 positionIterations = 3;   //how strongly to correct position
  
  GGJ::Context::getSingleton()._world.m_world->Step( timeStep, velocityIterations, positionIterations);
}

void				OnDivideEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	std::cout << "Event !" << std::endl;
	context._world.car->divide();
	
}
void				mainCallback(void*)
{
}
