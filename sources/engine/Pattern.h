#ifndef PATTERN_H
#define PATTERN_H
//
#include <Box2D/Box2D.h>

class Pattern
{


    public:

        int relativeHorizontalSlide;
        int relativeVerticalSlide;

        /**
        * Set up the blocks
        */
        Pattern(int relativeVSlide=0, int relativeHSlide=0);
        virtual void create();
        void createTriangle1(b2Vec2);
        void createTriangle2(b2Vec2);
        void createCassis(b2Vec2);
        void createJump1(b2Vec2);
        void createJump2(b2Vec2);
        void createJump3(b2Vec2);
        void createBar(b2Vec2);
        ~Pattern(){}
};

#endif