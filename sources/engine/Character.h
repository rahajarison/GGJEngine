#ifndef CHARACTER_H
#define CHARACTER_H
//
#include <Box2D/Box2D.h>

class Character
{
    private:
        b2Body* body;
        int MaxSpeed;
        int MaxAngularRotation;

    public:

        Character();
        ~Character(){}

        b2Body* getBody(){return 0;}
        int getVelocity(){return 0;}
        double getRotation(){return 0;}
        int getPosition(){return 0;}
        int getMaxSpeed(){return 0;}
        int getMaxAngularRotation(){return 0;}
};

#endif