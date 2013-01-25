#ifndef NUTRIMENT_COLISION_H
#define NUTRIMENT_COLISION_H

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
            }

        }

        void EndContact(b2Contact* contact){

        }
};