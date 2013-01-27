#ifndef PATTERN_H
#define PATTERN_H

class Pattern
{
    public:

        int x;
        Pattern(int x) : x(x) {} 
        virtual void create(){}
        ~Pattern();

};

#endif
