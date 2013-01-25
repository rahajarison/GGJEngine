#ifndef CHARACTER_H
#define CHARACTER_H

#include <Box2D/Box2D.h>

class character
{
    private:
        b2Body body;
        int MaxSpeed;
        int MaxAngularRotation;
    public:
        character();
        ~character();

        b2BodyDef getBody();
        int getVelocity();
        double getRotation();
        int getPosition();
        int getMaxSpeed();
        int getMaxAngularRotation();
};

#endif