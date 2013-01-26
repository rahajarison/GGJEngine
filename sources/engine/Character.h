#ifndef CHARACTER_H
#define CHARACTER_H
//
#include <Box2D/Box2D.h>
#include <vector>

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
        void update();
        void divide();
};

#endif