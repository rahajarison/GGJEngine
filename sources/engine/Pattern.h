#ifndef PATTERN_H
#define PATTERN_H

#include "Define.h"

class Pattern
{
    public:

        int x;
        Pattern(int x) : x(x) {} 
        virtual void create(){}
        ~Pattern() {}

};

#endif
