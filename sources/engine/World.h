#ifndef WORLD_H
#define WORLD_H
//
#include "Pattern.h"
#include "Character.h"
#include <vector>
#include <Box2D/Box2D.h>
#include "Pattern.h"

using namespace std;

class World
{       

    public:

        static b2World* m_world;
        vector<Pattern*> patternList;
        static Character* car;
        /**
        * Generate pattern order
        */
        World();
        ~World() { }
};

#endif
