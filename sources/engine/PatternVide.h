#ifndef PATTERN_VIDE_H
#define PATTERN_VIDE_H

#include "Pattern.h"

class PatternVide : Pattern
{
public:
    PatternVide(int x) : Pattern(x);
    void create(){
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
        polygonShape.SetAsBox( 1, 512);//ground
        staticBody->CreateFixture(&myFixtureDef);

        myBodyDef.position.Set(x+512,800);
        staticBody = World::m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsBox( 1, 512;//ground
        staticBody->CreateFixture(&myFixtureDef);
    }
    ~PatternVide();
};

