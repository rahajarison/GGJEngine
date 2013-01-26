#ifndef WORLD_H
#define WORLD_H
//
#include "Pattern.h"
#include "Character.h"
#include <vector>
#include <Box2D/Box2D.h>

using namespace std;

class World
{       

    public:

        static b2World* m_world;
        vector<Pattern*> patternList;
        Character cell;

        /**
        * Generate pattern order
        */
        World() : cell()
        {

            patternList.push_back(new Pattern());
            patternList[0]->create();
        }
        ~World() { }
};

#endif