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
        // vector<Pattern*> patternList;
        static Character* car;
        /**
        * Generate pattern order
        */
        World()
        {
            // patternList.push_back(new PatternFall1(0, 0));
            // patternList.push_back(new PatternFall2(40, 0));
            // patternList.push_back(new PatternFall3(80, 0));
            // patternList.push_back(new PatternFall4(80, 40));
            // patternList.push_back(new PatternFall5(80, 80));
            // patternList.push_back(new PatternFall6(80, 120));
            // patternList[0]->create();
            // patternList[1]->create();
            // patternList[2]->create();
            // patternList[3]->create();
            // patternList[4]->create();
            // patternList[5]->create();
        }
        ~World() { }
};

#endif
