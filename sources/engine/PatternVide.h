#ifndef PATTERN_VIDE_H
#define PATTERN_VIDE_H

#include "Pattern.h"

class PatternVide : public Pattern
{
public:
    PatternVide(int x);
    void create(void);

    ~PatternVide(void);
};

#endif