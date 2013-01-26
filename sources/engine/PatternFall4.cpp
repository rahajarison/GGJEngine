#include "PatternFall4.h"
#include "NutrientCollision.h"
#include "World.h"
#include "Nutrient.h"

void PatternFall4::create(){
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
    polygonShape.SetAsBox( 40, 1, b2Vec2(0, 0), 0);//ceilling
    staticBody->CreateFixture(&myFixtureDef);

    myBodyDef.position.Set(0+relativeHorizontalSlide, 15+relativeVerticalSlide);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 40, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);



    createCassis(b2Vec2(20+relativeHorizontalSlide,15+relativeVerticalSlide));

    World::m_world->SetContactListener(nc);
    //new Nutrient(12, 3+relativeHorizontalSlide,2+relativeVerticalSlide);
}