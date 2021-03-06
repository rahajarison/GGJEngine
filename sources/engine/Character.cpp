#include <iostream>
#include "Character.h"
#include "World.h"
#include "Define.h"
//
Character::Character() : bodies()
{
    long int type = character;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(100, 400);   // the body's origin position.
    bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
    bodies.push_back(World::m_world->CreateBody(&bodyDef));

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = 15;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
    bodies[0]->CreateFixture(&myFixtureDef); //add a fixture to the body
    bodies[0]->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    bodies[0]->SetUserData((void*) type);
    isDivided = false;
    nutris = 0;
    MaxSpeed = 30;
}

void Character::up()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        b2Vec2 vel = bodies[i]->GetLinearVelocity();
        float force = 0;
        if(vel.x <  MaxSpeed ) 
            force =  FORCE;

        bodies[i]->ApplyForce( b2Vec2(0, -force), bodies[i]->GetWorldPoint(b2Vec2(0,0)) );
    }
}
void Character::down()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        b2Vec2 vel = bodies[i]->GetLinearVelocity();
        float force = 0;
        if(vel.x <  MaxSpeed ) 
            force =  FORCE;

        bodies[i]->ApplyForce( b2Vec2(0, force), bodies[i]->GetWorldPoint(b2Vec2(0,1)) );
    }
}
void Character::right()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        b2Vec2 vel = bodies[i]->GetLinearVelocity();
        float force = 0;
        if(vel.x <  MaxSpeed ) 
            force =  FORCE;

        bodies[i]->ApplyForce( b2Vec2(force, 0), bodies[i]->GetWorldPoint(b2Vec2(0,1)) );
    }
}
void Character::left()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        b2Vec2 vel = bodies[i]->GetLinearVelocity();
        float force = 0;
        if(vel.x <  MaxSpeed ) 
            force =  FORCE;

        bodies[i]->ApplyForce( b2Vec2(-force, 0), bodies[i]->GetWorldPoint(b2Vec2(0,1)) );
    }
}

void Character::divide()
{
    long int type = character;
    b2Vec2 posIni = bodies[0]->GetPosition();
    b2Vec2 speed = bodies[0]->GetLinearVelocity();
    float grav = bodies[0]->GetGravityScale();
    float scale = bodies[0]->GetFixtureList()->GetAABB(0).GetExtents().x * 2;
    if(!isDivided && nutris > 0)
    {
        bodies.clear();
        b2BodyDef bodyDef;
        if(nutris <= DIVIDE)
        {
            for(int i = 0; i < nutris; ++i)
            {
                bodyDef.type = b2_dynamicBody;
                bodyDef.position.Set(posIni.x, posIni.y);   // the body's origin position.
                bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
                bodyDef.linearDamping = 0.0f;
                bodyDef.angularDamping = 0.01f;
                bodies.push_back(World::m_world->CreateBody(&bodyDef));

                b2CircleShape circleShape;
                circleShape.m_p.Set(0, 0);          //position, relative to body position
                circleShape.m_radius = scale/nutris;           //radius
                b2FixtureDef myFixtureDef;
                myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
                bodies[i]->CreateFixture(&myFixtureDef); //add a fixture to the body

                bodies[i]->SetUserData((void*)type);
            }
        }
        else
        {
            for(int i = 0; i < DIVIDE; ++i)
            {
                bodyDef.type = b2_dynamicBody;
                bodyDef.position.Set(posIni.x, posIni.y);   // the body's origin position.
                bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
                bodyDef.linearDamping = 0.0f;
                bodyDef.angularDamping = 0.01f;
                bodies.push_back(World::m_world->CreateBody(&bodyDef));

                b2CircleShape circleShape;
                circleShape.m_p.Set(0, 0);          //position, relative to body position
                circleShape.m_radius = scale/DIVIDE;           //radius
                b2FixtureDef myFixtureDef;
                myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
                bodies[i]->CreateFixture(&myFixtureDef); //add a fixture to the body

                bodies[i]->SetUserData((void *)type);
            }
        }
        isDivided = !isDivided;
    }   
}

void Character::fusion()
{
    long int type = character;
    b2Vec2 posIni = bodies[0]->GetPosition();
    b2Vec2 speed = bodies[0]->GetLinearVelocity();
    
    if(isDivided)
    {
        bodies.clear();
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(posIni.x, posIni.y);   // the body's origin position.
        bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
        bodyDef.linearDamping = 0.0f;
        bodyDef.angularDamping = 0.01f;
        bodies.push_back(World::m_world->CreateBody(&bodyDef));

        b2CircleShape circleShape;
        circleShape.m_p.Set(0, 0);          //position, relative to body position
        circleShape.m_radius = nutris * 0.025f + 1;           //radius
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
        bodies[0]->CreateFixture(&myFixtureDef); //add a fixture to the body

        bodies[0]->SetUserData((void*)type);

        isDivided = !isDivided;
    }
}

void Character::beat()
{
    for(int i = 0; i < bodies.size(); ++i)
    {
        bodies[i]->ApplyLinearImpulse( b2Vec2(IMPULSE,0), bodies[i]->GetWorldCenter() );
    }   
}


