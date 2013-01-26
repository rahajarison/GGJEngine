#include "PatternFall6.h"
#include "NutrientCollision.h"
#include "World.h"
#include "Nutrient.h"

void PatternFall6::create(){
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

    myBodyDef.position.Set(0+relativeHorizontalSlide, 25+relativeVerticalSlide);
    staticBody = World::m_world->CreateBody(&myBodyDef);
    polygonShape.SetAsBox( 40, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);

    createJump1(b2Vec2(25+relativeHorizontalSlide,25+relativeVerticalSlide));
    createBar(b2Vec2(20+relativeHorizontalSlide,7+relativeVerticalSlide));

    World::m_world->SetContactListener(nc);
    //new Nutrient(12, 3+relativeHorizontalSlide,2+relativeVerticalSlide);
}