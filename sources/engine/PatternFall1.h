#ifndef PATTERN_FALL_1_H
#define PATTERN_FALL_1_H

#include "Pattern.h"

class PatternFall1 : public Pattern
{
    public:
        PatternFall1(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall1(){

        }

};

#endif