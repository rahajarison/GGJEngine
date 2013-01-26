#include "World.h"
//
b2World* World::m_world=new b2World(b2Vec2(0, 0));
Character* World::car = new Character();