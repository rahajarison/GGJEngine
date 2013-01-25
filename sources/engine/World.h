#ifndef WORLD_H
#define WORLD_H

#include "Pattern.h"
#include <vector>
#include <Box2D/Box2D.h>

using namespace std;

class World
{       

    public:

        static b2World* m_world;
        vector<Pattern*> paternList;

        /**
        * Generate pattern order
        */
        World();
        ~World();
};

#endif