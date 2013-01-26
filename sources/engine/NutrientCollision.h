#ifndef NUTRIMENT_COLISION_H
#define NUTRIMENT_COLISION_H
//
#include "Define.h"
#include <iostream>

class NutrientCollision : public b2ContactListener
{
    public:

        NutrientCollision(){}
        ~NutrientCollision(){}

        void BeginContact(b2Contact* contact){
            void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
            void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
            if ( bodyAUserData && bodyBUserData ){
                std::cout<<"fiuck ya\n";
                long int a=(long int)(bodyAUserData);
                long int b=(long int)(bodyBUserData);
                std::cout<<a<<"\n";
                std::cout<<b<<"\n";
                if(a==nutrient){
                    //m_world->destroyBody(contact->GetFixtureA()->GetBody());
                    return;
                } 
                if (b==nutrient){
                    //m_world->destroyBody(contact->GetFixtureB()->GetBody());
                    return;
                }
                if (a==bouncingBlockTop){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(0,-BOUNCING), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockTop){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(0,-BOUNCING), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockBottom){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(0,BOUNCING), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockBottom){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(0,BOUNCING), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING, 0), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING, 0), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING, 0), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING, 0), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockTopLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,-BOUNCING/2), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockTopLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,-BOUNCING/2), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockTopRight){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,-BOUNCING/2), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockTopRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,-BOUNCING/2), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockBottomLeft){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,BOUNCING/2), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockBottomLeft){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(BOUNCING/2,BOUNCING/2), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (a==bouncingBlockBottomRight){
                    contact->GetFixtureB()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,BOUNCING/2), contact->GetFixtureB()->GetBody()->GetWorldCenter() );
                    return;
                }
                if (b==bouncingBlockBottomRight){
                    contact->GetFixtureA()->GetBody()->ApplyLinearImpulse( b2Vec2(-BOUNCING/2,BOUNCING/2), contact->GetFixtureA()->GetBody()->GetWorldCenter() );
                    return;
                }
            }
        }

        void EndContact(b2Contact* contact){

        }
};

#endif