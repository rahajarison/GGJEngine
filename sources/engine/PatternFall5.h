#ifndef PATTERN_FALL_5_H
#define PATTERN_FALL_5_H

#include "Pattern.h"

class PatternFall5 : public Pattern
{
    public:
        PatternFall5(int x, int y) : Pattern(x, y) {

        }
        virtual void create();
        ~PatternFall5(){

        }

};

#endif