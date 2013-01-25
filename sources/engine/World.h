#ifndef WORLD_H
#define WORLD_H

#include "Pattern.h"
#include <vector>

using namespace std;

class World
{
    private :

        vector<Pattern*> paternList;

    public:

        /**
        * Generate pattern order
        */
        World();
        ~World();
};

#endif