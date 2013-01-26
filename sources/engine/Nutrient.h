#ifndef NUTRIENT_H
#define NUTRIENT_H
//
#include <Box2D/Box2D.h>

class nutrient
{
    public:

        b2Body* body;
        int points;

        nutrient(int point, double x, double y);

        ~nutrient();

};

#endif