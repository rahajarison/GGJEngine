#ifndef PATTERN_FALL_3_H
#define PATTERN_FALL_3_H

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