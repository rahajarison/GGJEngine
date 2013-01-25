#ifndef CHARACTER_H
#define CHARACTER_H

#include <Box2D/Box2D.h>

class character
{
    private:
        b2BodyDef body;
        int MaxSpeed;
        int MaxAngularRotation;
    public:
        character();
        ~character();

        int getSpeed();
        int getRotation();
        int getPosition();
};

#endif