#include "Pattern.h"
#include "World.h"
#include "Nutrient.h"
#include "Define.h"
#include "NutrientCollision.h"

void createTriangle(b2Vec2 init)
{
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(init.x, init.y);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    //shape definition
    b2PolygonShape polygonShape;

    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;

    //add four walls to the static body
    polygonShape.SetAsBox( 32, 1, b2Vec2(init.x, init.y), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 8, 1, b2Vec2(init.x, init.y), 80 * DEGTORAD);//left border
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 31, 1, b2Vec2(8, 1), DEGTORAD * 90);//right border
    staticBody->CreateFixture(&myFixtureDef);
}

void createCassis(b2Vec2 pos){
    int radius=60;
    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y-(radius*2/3));
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    bodyDef.angle = 0.25f * b2_pi;      // the body's angle in radians.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0);          //position, relative to body position
    circleShape.m_radius = radius;           //radius
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);
}

void createJump1(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(1, 8, b2Vec2(-1,0), 135*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(5, 6);          //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(1, 6, b2Vec2(5, 0), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

void createJump2(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(1, 8, b2Vec2(0,0), 225*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(6, -6);         //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(6, 1, b2Vec2(0, -6), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

void createJump3(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(8, 1, b2Vec2(0,0), 45*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    b2CircleShape circleShape;
    circleShape.m_p.Set(-6, -6);        //position, relative to body position
    circleShape.m_radius = 1;           //radius
    
    myFixtureDef.shape = &circleShape;
    body->CreateFixture(&myFixtureDef);

    rect.SetAsBox(6, 1, b2Vec2(0, -6), 0*DEGTORAD);
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

void createBar(b2Vec2 pos){

    b2Vec2 newPos=*new b2Vec2(pos.x,pos.y);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(newPos.x, newPos.y);   // the body's origin position.
    b2Body* body= World::m_world->CreateBody(&bodyDef);

    b2PolygonShape rect;
    rect.SetAsBox(8, 1, b2Vec2(0,0), 45*DEGTORAD);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);

    myFixtureDef.shape=&rect;
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

}

//
Pattern::Pattern(int relativeVSlide)
: relativeVerticalSlide(relativeVSlide)
{
    //set the block into the world
}

void Pattern::create(){

    NutrientCollision* nc=new NutrientCollision();
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;

    //shape definition
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(1, 1); //a 2x2 rectangle
  
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;
    
    //create dynamic body
    myBodyDef.position.Set(0, 10);
    b2Body* body = World::m_world->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);
    body->SetUserData((void*)block);

    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0, 0);
    b2Body* staticBody = World::m_world->CreateBody(&myBodyDef);
    
    //GROUND
    polygonShape.SetAsBox( 40, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);

    /*Tourniquets*/
    //body and fixture defs - the common parts

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1;

    //two shapes
    b2PolygonShape boxShape;
    boxShape.SetAsBox(4,1);
    b2CircleShape circleShape;
    circleShape.m_radius = 1;     

    //make box a little to the left
    bodyDef.position.Set(-5, 6);
    fixtureDef.shape = &boxShape;
    b2Body* m_bodyA = World::m_world->CreateBody( &bodyDef );
    m_bodyA->CreateFixture( &fixtureDef );
    body->SetUserData((void*)block);
    //set the angle
    m_bodyA->SetTransform(m_bodyA->GetPosition(), 90*DEGTORAD);
    //and circle a little to the right
    bodyDef.type=b2_staticBody;
    bodyDef.position.Set( -5, 6);
    fixtureDef.shape = &circleShape;
    b2Body* m_bodyB = World::m_world->CreateBody( &bodyDef );
    m_bodyB->CreateFixture( &fixtureDef );
    body->SetUserData((void*)block);


    long int a=(long int)(body->GetUserData());


    cout<<a<<endl;

    //add jolong int

    b2RevoluteJointDef revoluteJointDef;
    revoluteJointDef.bodyA = m_bodyA;
    revoluteJointDef.bodyB = m_bodyB;
    revoluteJointDef.collideConnected = false;
    revoluteJointDef.localAnchorA.Set(0,0);//the top right corner of the box
    revoluteJointDef.localAnchorB.Set(0,0);//center of the circle
    b2RevoluteJoint* m_joint = (b2RevoluteJoint*)World::m_world->CreateJoint( &revoluteJointDef );

    fixtureDef.shape=&boxShape;
    bodyDef.position.Set(8, 0.2);
    bodyDef.type=b2_staticBody;
    fixtureDef.isSensor=true;
    b2Body* bumper = World::m_world->CreateBody( &bodyDef );

    bumper->SetUserData((void*)bouncingBlockBottom);
    bumper->CreateFixture(&fixtureDef);

    
    a=(long int)(bumper->GetUserData());
    cout<<"a " <<a<<endl;

    World::m_world->SetContactListener(nc);
    new Nutrient(12, 3,2);
}