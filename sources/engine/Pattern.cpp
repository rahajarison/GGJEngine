#include "Pattern.h"
#include "World.h"
#include "Nutrient.h"
#include "Define.h"
#include "NutrientCollision.h"

void Pattern::createTriangle1(b2Vec2 pos)
{
    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(8, 1, b2Vec2(1, 3), 160*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(1, 3, b2Vec2(-6.5, 3), 160*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);
}

void Pattern::createTriangle2(b2Vec2 pos)
{
    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(8, 1, b2Vec2(1, 2), 15*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(1, 3, b2Vec2(8.5, 0), 190*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);
}

void Pattern::createCassis(b2Vec2 pos){
    int radius=60;
    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y-(radius*2/3));
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = radius;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);
}

//img1
void Pattern::createJump1(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(1, 8, b2Vec2(-1,0), 135*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(5, 6);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(1, 6, b2Vec2(5, 0), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

//img2
void Pattern::createJump2(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(1, 8, b2Vec2(0,0), 225*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(6, -6);         //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(6, 1, b2Vec2(0, -6), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

//img3
void Pattern::createJump3(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(8, 1, b2Vec2(0,0), 45*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(-6, -6);        //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(6, 1, b2Vec2(0, -6), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

void Pattern::createBar(b2Vec2 pos, bool vertical){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(0.05f, 10, b2Vec2(0,0), 0);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

void Patern::createSensor(b2Vec2 pos)
{
    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
    bodies[0]->CreateFixture(&myFixtureDef); //add a fixture to the body
    bodies[0]->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    bodies[0]->SetUserData((void*) type);
    
    body->SetUserData((void*)block);
}

void Patern::bubbles()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
    bodies[0]->CreateFixture(&myFixtureDef); //add a fixture to the body
    bodies[0]->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    bodies[0]->SetUserData((void*) type);
    
    body->SetUserData((void*)block);
}

//
Pattern::Pattern(int relativeVSlide, int relativeHSlide)
: relativeVerticalSlide(relativeVSlide), relativeHorizontalSlide(relativeHSlide)
{
    //set the block into the world
}

void Pattern::create(){


}