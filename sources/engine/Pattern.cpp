#include "Pattern.h"
#include "World.h"
#include "Nutrient.h"
#include "Define.h"
#include "NutrientCollision.h"

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