#include "World.h"
#include "PatternVide.h"
#include "PatternCassis.h"
#include "PatternDash.h"
#include "PatternBump.h"
#include "Pattern1.h"
//
b2World* World::m_world=new b2World(b2Vec2(0, 10));
Character* World::car = new Character();
World::World(void)
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