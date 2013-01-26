#ifndef CHARACTER_H
#define CHARACTER_H
//
#include <Box2D/Box2D.h>
#include <vector>
#include "Define.h"

class Character
{
    private:
        

    public:

        Character();
        ~Character(){}

        std::vector <b2Body*> bodies;
        int MaxSpeed;
        int MaxAngularRotation;
        int nutris;
        bool isDivided;

        b2Body* getBody(){return 0;}
        int getVelocity(){return 0;}
        double getRotation(){return 0;}
        int getMaxSpeed(){return 0;}
        int getMaxAngularRotation(){return 0;}
        static bool isCharacter(b2Body* body){
            void* userData = body->GetUserData();
            long int type=(long int)(userData);
            return type==character;
        }
        
        void up();
        void down();
        void left();
        void right();
        void divide();
        void fusion();
        void beat();
};

#endif