#ifndef PATTERN_CASSIS_H
#define PATTERN_CASSIS_H

#include "Pattern.h"

class PatternCassis : public Pattern
{
public:
    PatternCassis(int x) : Pattern(x){}
    void create();
    ~PatternCassis();
};

#endif