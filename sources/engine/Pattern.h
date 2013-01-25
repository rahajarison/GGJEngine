#ifndef PATTERN_H
#define PATTERN_H
//
#include <Box2D/Box2D.h>

class Pattern
{
    private :


    public:

        int relativeVerticalSlide;

        /**
        * Set up the blocks
        */
        Pattern(int relativeVSlide=0);
        void create();
        ~Pattern(){}
};

#endif