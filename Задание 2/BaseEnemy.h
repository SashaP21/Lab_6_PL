#ifndef _2_BASEENEMY_H
#define _2_BASEENEMY_H
#include "BaseCharacter.h"
#include "Weapon.h"

class BaseEnemy : public BaseCharacter {
    Weapon weapon;
public:
    BaseEnemy(double pos_x, double pos_y, double hp, const Weapon &weapon);
    void hit(BaseCharacter& target) const;
    friend std::ostream& operator<<(std::ostream& out, const BaseEnemy& e);
};

#endif //_2_BASEENEMY_H