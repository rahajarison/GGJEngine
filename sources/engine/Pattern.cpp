#include "Pattern.h"
#include "World.h"
#include "Nutrient.h"
//
Pattern::Pattern(int relativeVSlide)
: relativeVerticalSlide(relativeVSlide)
{
    //set the block into the world
}

void Pattern::create(){
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    
    //shape definition
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(1, 1); //a 2x2 rectangle
  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;
    
    //create dynamic body
    myBodyDef.position.Set(0, 10);
    b2Body* body = World::m_world->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0, 0);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    
    //add four walls to the static body
    polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);


    new nutrient(12, 3,2);
}