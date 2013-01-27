#include "PatternDash.h"
#include "Define.h"
#include "World.h"

void PatternDash::create(){
    
    //shape definition
       b2BodyDef myBodyDef;

    //shape definition
    b2PolygonShape polygonShape;
    
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(x+512,TOP);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 512, 1);//ground
    staticBody->CreateFixture(&myFixtureDef);
    staticBody->SetUserData((void*)block);

    myBodyDef.position.Set(x+512,DOWN);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 512, 1);//ground
    staticBody->CreateFixture(&myFixtureDef);
    staticBody->SetUserData((void*)block);

    int xp=300;
    myBodyDef.position.Set(x+xp+(480/2), TOP+329/2);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 480/2, 329/2);
    staticBody->CreateFixture(&myFixtureDef);
    staticBody->SetUserData((void*)grosRect);

    myBodyDef.position.Set(x+xp-100, TOP);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox(100, 1);//ground
    myFixtureDef.isSensor=true;
    staticBody->SetUserData((void*)bouncingBlockBottom);
    staticBody->CreateFixture(&myFixtureDef);

}