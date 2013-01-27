#ifndef PATTERN_DASH_H
#define PATTERN_DASH_H

#include	"Pattern.h"

class PatternDash : public Pattern
{
public:
    PatternDash(int x) : Pattern(x){}
    void create();
    ~PatternDash();
};

#endif