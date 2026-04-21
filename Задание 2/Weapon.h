#ifndef _2_WEAPON_H
#define _2_WEAPON_H

#include <string>
#include "BaseCharacter.h"

class Weapon {
    std::string name;
    double damage;
    double range;
public:
    Weapon(const std::string& name = "Unknown", double damage = 0, double range = 0);
    void hit(const BaseCharacter& actor, BaseCharacter& target) const;
    friend std::ostream& operator<<(std::ostream& out, const Weapon& w);
    friend std::istream& operator>>(std::istream& in, Weapon& w);
};


#endif //_2_WEAPON_H