#include	<Box2D/Box2D.h>
#include	"PatternVide.h"
#include	"World.h"

PatternVide::PatternVide(int x)  : Pattern(x) { }
PatternVide::~PatternVide(void) { }
void PatternVide::create(void)
{
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
}