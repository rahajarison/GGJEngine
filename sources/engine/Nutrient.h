#ifndef NUTRIENT_H
#define NUTRIENT_H

class nutrient : public SpecialCollisionObject
{
    private:
        int points;
    public:
        nutrient(int);
        ~nutrient();
};

#endif