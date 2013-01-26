#ifndef PATTERN_FALL_6_H
#define PATTERN_FALL_6_H

#include "Pattern.h"

class PatternFall6 : public Pattern
{
    public:
        PatternFall6(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall6(){

        }

};

#endif