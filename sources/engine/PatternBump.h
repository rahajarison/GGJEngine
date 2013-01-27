#ifndef PATTERN_BUMP_H
#define PATTERN_BUMP_H

#include "Pattern.h"

class PatternBump : public Pattern
{
public:
	PatternBump(int x) : Pattern(x) { }
	virtual void create(void);
	~PatternBump(void) { }
};

#endif