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

        public enum types 
        {
            "character", "nutrient", "block", "bouncingBlock"
        };
        
        /**
        * Generate pattern order
        */
        World();
        ~World();
};

#endif