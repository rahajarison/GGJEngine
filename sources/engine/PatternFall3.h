#ifndef PATTERN_FALL_1_H
#define PATTERN_FALL_1_H

#include "Pattern.h"

class PatternFall3 : public Pattern
{
    public:
        PatternFall3(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall3(){

        }

};

#endif