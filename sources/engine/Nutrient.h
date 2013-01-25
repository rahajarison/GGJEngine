#ifndef NUTRIENT_H
#define NUTRIENT_H

class nutrient : public SpecialCollisionObject
{
    public:
        nutrient(int);
        ~nutrient();
        int points;
};

#endif