#include "Pattern.h"


void Pattern::create(){
    b2BodyDef myBodyDef;

    //shape definition
    b2PolygonShape polygonShape;

  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(x+512,0);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData(block);
    polygonShape.SetAsBox( 1, 512);//ground
    staticBody->CreateFixture(&myFixtureDef);

    myBodyDef.position.Set(x+512,800);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData(block);
    polygonShape.SetAsBox( 1, 512;//ground
    staticBody->CreateFixture(&myFixtureDef);
    int radius=100;
    b2CircleShape circleShape;
    myFixtureDef.shape=circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = radius;
    myBodyDef.position.Set(x+512, radius*9/10);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData(block);
    staticBody->CreateFixture(&myFixtureDef);


}