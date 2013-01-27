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

void				reloadCells(GGJ::Context* context)
{
	b2Body*	body = context->_world.m_world->GetBodyList();
	while (body != NULL)
	{
		if (Character::isCharacter(body))
			context->attachObject(*(new ObjCell(body)));
		body = body->GetNext();
	}
}
void				OnDivideEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->removeObjectsWithTag("cell");
	context->_world.car->divide();	
	reloadCells(context);
}
void				OnImpulseEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->_world.car->beat();
}
void				OnFusionEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->removeObjectsWithTag("cell");
	context->_world.car->fusion();
	reloadCells(context);
}

void				OnRightEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->_world.car->right();
}
void				OnLeftEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);

	context->_world.car->left();
}
void				OnFrontEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);
	context->_world.car->up();
}
void				OnBackEvent(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);
	context->_world.car->down();
}


void				cameraCallback(void* params)
{
	GGJ::Context*		context = reinterpret_cast<GGJ::Context*>(params);
	b2Body* body = context->_world.car->bodies[0];
	sf::View& camera =	context->accessView();

	camera.SetCenter(body->GetPosition().x + 200, 400);

	// std::cout << "Position: " << body->GetPosition().y * COEF_DISPLAY << " et Camera: " << camera.GetCenter().y << std::endl;
	// if (body->GetPosition().y * COEF_DISPLAY >= camera.GetCenter().y - 200)
	// {
		// camera.SetCenter(body->GetPosition().x * COEF_DISPLAY, body->GetPosition().y * COEF_DISPLAY - 200);
	// camera.SetCenter(body->GetPosition().x * COEF_DISPLAY, body->GetPosition().y * COEF_DISPLAY + 400);
	// }
	// camera.SetCenter(400, body->GetPosition().y * COEF_DISPLAY);
}
void				mainCallback(void*)
{
	GGJ::Context* context =	&GGJ::Context::getSingleton();

	context->_world.car->right();
	// context->_world.car->update();
}
