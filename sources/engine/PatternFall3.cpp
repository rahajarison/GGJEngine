#include "PatternFall2.h"
#include "NutrientCollision.h"
#include "World.h"
#include "Nutrient.h"

void PatternFall3::create(){
    NutrientCollision* nc=new NutrientCollision();
    b2BodyDef myBodyDef;

    //shape definition
    b2PolygonShape polygonShape;

  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0+relativeHorizontalSlide, 0+relativeVerticalSlide);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 40, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);

    myBodyDef.position.Set(15+relativeHorizontalSlide, 0+relativeVerticalSlide);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 25, 1, b2Vec2(15, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);

    createJump3(b2Vec2(15,30));

    World::m_world->SetContactListener(nc);
    new Nutrient(12, 3+relativeHorizontalSlide,2+relativeVerticalSlide);
}