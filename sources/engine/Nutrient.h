#ifndef NUTRIENT_H
#define NUTRIENT_H
//
#include <Box2D/Box2D.h>

class Nutrient
{
    public:

        b2Body* body;
        int points;

        Nutrient(int point, double x, double y);

        ~Nutrient();

};

#endif