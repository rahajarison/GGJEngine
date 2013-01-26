#ifndef PATTERN_FALL_4_H
#define PATTERN_FALL_4_H

#include "Pattern.h"

class PatternFall4 : public Pattern
{
    public:
        PatternFall4(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall4(){

        }

};

#endif