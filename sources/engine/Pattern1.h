#ifndef PATTERN_UN_H
#define PATTERN_UN_H

#include "Pattern.h"

class Pattern1 : public Pattern
{
public:
    Pattern1();
    void create(){
        b2BodyDef myBodyDef;

        //shape definition
        b2PolygonShape polygonShape;

      
        //fixture definition
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &polygonShape;
        myFixtureDef.density = 1;

        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(x+512,28);
        b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox( 512, 1);//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(block);

        myBodyDef.position.Set(x+512,772);
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox( 512, 1);//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(block);

        myBodyDef.position.Set(x+512,150);
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox( 30, 150);//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(block);

        myBodyDef.position.Set(x+542,200);
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox(2,10);//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(bouncingBlockLeft);

        myBodyDef.position.Set(x+732,28);
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox( 30, 150, b2Vec2( 0, 0), 45*DEGTORAD);//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(block);

        myBodyDef.position.Set(x+742, );
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox(2,10, b2Vec2(0,0), 45*DEGTORAD );//ground
        staticBody->CreateFixture(&myFixtureDef);
        staticBody->SetUserData(bouncingBlockBottomRight);
    }
    ~PatternVide();
};

#endif

