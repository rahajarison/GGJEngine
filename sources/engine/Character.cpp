#include "Character.h"
#include "World.h"
#include "Define.h"
//
Character::Character()
{
    types type = character;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 2.0f);   // the body's origin position.
    bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.01f;
    bodies[0] = World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
    bodies[0]->CreateFixture(&myFixtureDef); //add a fixture to the body

    bodies[0]->SetUserData(&type);
}

void Character::update()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        b2Vec2 vel = bodies[i]->GetLinearVelocity();
        float force = 0;
        if(vel.x <  MaxSpeed ) 
            force =  FORCE;

        bodies[i]->ApplyForce( b2Vec2(force,0), bodies[i]->GetWorldPoint(b2Vec2(0,1)) );
    }
}

void Character::divide()
{
    if(!isDivided)
    {
        if(nutris <= DIVIDE)
        {
            b2Vec2 posIni = bodies[0]->GetPosition();
            b2Vec2 speed = bodies[0]->GetLinearVelocity();
            for(int i = 0; i < nutris; ++i)
            {

            }
        }
        else
        {
            for(int i = 0; i < DIVIDE; ++i)
            {

            }
        }
    }   
}




