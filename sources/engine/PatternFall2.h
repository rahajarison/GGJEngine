#ifndef PATTERN_FALL_1_H
#define PATTERN_FALL_1_H

#include "Pattern.h"

class PatternFall2 : public Pattern
{
    public:
        PatternFall2(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall2(){

        }

};

#endif