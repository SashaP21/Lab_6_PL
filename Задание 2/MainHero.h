#ifndef _2_MAINHERO_H
#define _2_MAINHERO_H

#include <string>
#include <vector>
#include "Weapon.h"
#include "BaseCharacter.h"
#include "BaseEnemy.h"

class MainHero : public BaseCharacter {
    std::string name;
    std::vector<Weapon> inventory;
    int current_weapon_index = -1;
public:
    MainHero(double pos_x, double pos_y, double hp, const std::string& name = "Unknown");
    void hit(BaseEnemy& target) const;
    void add_weapon(const Weapon& weapon);
    void next_weapon();
    void heal(double amount);
};

#endif //_2_MAINHERO_H