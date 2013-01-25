#include "Character.h"
#include "World.h"
#include "Define.h"

Character::Character()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 2.0f);   // the body's origin position.
    bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.01f;
    body = &World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
    body.CreateFixture(&myFixtureDef); //add a fixture to the body

    body.SetUserData(types.character);
}