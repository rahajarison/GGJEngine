#ifndef WORLD_H
#define WORLD_H
//
#include "Pattern.h"
#include "Character.h"
#include <vector>
#include <Box2D/Box2D.h>
#include "Pattern.h"
#include "PatternVide.h"
#include "PatternCassis.h"

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
        World()
        {

            patternList.push_back(new PatternVide(0));
            patternList.push_back(new PatternCassis(1024));
            patternList.push_back(new PatternVide(2048));
            patternList.push_back(new PatternDash(3132));
            patternList.push_back(new PatternBump(4216));
            patternList.push_back(new Pattern1(5300));
            patternList[0]->create();
            patternList[1]->create();
            patternList[2]->create();
            patternList[3]->create();
            patternList[4]->create();
            patternList[5]->create();

        }
        ~World() { }
};

#endif
