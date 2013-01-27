#include "Define.h"
#include "World.h"
#include "PatternCassis.h"



void PatternCassis::create(){
        b2BodyDef myBodyDef;
    b2PolygonShape polygonShape;

  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(x+512,TOP);
    b2Body* staticBody = m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData((void*)block);
    polygonShape.SetAsBox(512, 1 );//ground
    staticBody->CreateFixture(&myFixtureDef);

    myBodyDef.position.Set(x+512,DOWN);
    staticBody = m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData((void*)block);
    polygonShape.SetAsBox(512, 1);//ground
    staticBody->CreateFixture(&myFixtureDef);
    int radius=100;
    b2CircleShape circleShape;
    myFixtureDef.shape=&circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = radius;
    myBodyDef.position.Set(x+512, -radius*8/10);
    staticBody = m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData((void*)block);
    staticBody->CreateFixture(&myFixtureDef);



}