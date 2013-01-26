#ifndef NUTRIMENT_COLISION_H
#define NUTRIMENT_COLISION_H
//
#include "Define.h"

class NutrientCollision : ContactListener
{
    public:
        NutrientCollision();
        ~NutrientCollision();

        void BeginContact(b2Contact* contact){
            void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
            void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
            if ( bodyAUserData && bodyBUserData ){
                Types a=static_cast<Define::Types*>(bodyAUserData);
                Types b=static_cast<Define::Types*>(bodyBUserData);
                if(a==Types.nutriment){
                    World::m_world->destroyBody(contact->GetFixtureA()->GetBody());
                    return;
                } 
                if (b==Types.nutrient){
                    World::m_world->destroyBody(contact->GetFixtureB()->GetBody());
                    return;
                }
                if (a==Types.bouncingBlockTop){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(0,-BOUNCING), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockTop){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(0,-BOUNCING), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockBottom){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(0,BOUNCING), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockBottom){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(0,BOUNCING), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING, 0), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING, 0), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockRight){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING, 0), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING, 0), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockTopLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,-BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockTopLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,-BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockTopRight){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,-BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockTopRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,-BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockBottomLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockBottomLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (a==Types.bouncingBlockBottomRight){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
                if (b==Types.bouncingBlockBottomRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,BOUNCING/2), body->GetWorldCenter() );
                    return;
                }
            }
        }

        void EndContact(b2Contact* contact){

        }
};