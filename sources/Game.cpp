#include		<iostream>
#include		<GGJContext.hpp>
#include		"ObjCell.hpp"
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
	context->removeObjectsWithTag("cell");
	context->_world.car->divide();	
	b2Body*	body = context->_world.m_world->GetBodyList();

	while (body != NULL)
	{
		context->attachObject(*(new ObjCell(body)));
		body = body->GetNext();
	}
}
void				OnImpulseEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->_world.car->beat();
}
void				cameraCallback(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	b2Body* body = context->_world.car->bodies[0];
	context->accessView().SetCenter(400, body.GetPosition().y);
}
void				mainCallback(void*)
{
	GGJ::Context* context =	&GGJ::Context::getSingleton();

	context->_world.car->update();
}
