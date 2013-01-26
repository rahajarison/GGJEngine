#ifndef WORLD_H
#define WORLD_H
//
#include "Pattern.h"
#include "Character.h"
#include <vector>
#include <Box2D/Box2D.h>
#include "PatternFall1.h"

using namespace std;

class World
{       

    public:

        static b2World* m_world;
        vector<Pattern*> patternList;
        Character* car;
        /**
        * Generate pattern order
        */
        World()
        {
            patternList.push_back(new PatternFall1(0, 0));
            // patternList[0]->create();
            car = new Character();
        }
        ~World() { }
};

#endif