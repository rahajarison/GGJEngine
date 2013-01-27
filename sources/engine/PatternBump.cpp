#include "PatternBump.h"
#include "Define.h"
#include "World.h"

void PatternBump::create(){
    //shape definition
    b2BodyDef myBodyDef;
    b2PolygonShape polygonShape;
  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(x+512,TOP);
    b2Body* staticBody = m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 512, 1);//ground
    staticBody->CreateFixture(&myFixtureDef);
    staticBody->SetUserData((void*)block);

    myBodyDef.position.Set(x+512,DOWN/10);
    staticBody = m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 512, 1);//ground
    staticBody->CreateFixture(&myFixtureDef);
    staticBody->SetUserData((void*)block);

    for(int i=2;i<5;++i){
        int xp=i*200;
        //bas
        myBodyDef.position.Set(x+xp-100, DOWN/10-2);
        staticBody = m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox(100, 1);//ground
        myFixtureDef.isSensor=true;
        staticBody->SetUserData((void*)bouncingBlockTop);
        staticBody->CreateFixture(&myFixtureDef);
        //haut
        myBodyDef.position.Set(x+xp-100, TOP+2);
        staticBody = m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox(100, 1);//ground
        myFixtureDef.isSensor=true;
        staticBody->SetUserData((void*)bouncingBlockBottom);
        staticBody->CreateFixture(&myFixtureDef);
    }

    
    /*myFixtureDef.isSensor=false;
    myBodyDef.type = b2_dynamicBody;
    myBodyDef.linearDamping=0.0f;
    myFixtureDef.shape=&polygonShape;
    myBodyDef.position.Set(400, 40);
    polygonShape.SetAsBox(10, 10);//ground
    staticBody = m_world->CreateBody(&myBodyDef);
    staticBody->SetUserData((void*)character);
    staticBody->CreateFixture(&myFixtureDef);
    */

}