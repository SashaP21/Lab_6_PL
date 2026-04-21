#include "BaseEnemy.h"
#include <iostream>

BaseEnemy::BaseEnemy(double pos_x, double pos_y, double hp, const Weapon &weapon) : BaseCharacter(pos_x, pos_y, hp) {
    this->weapon = weapon;
};

void BaseEnemy::hit(BaseCharacter &target) const {
    weapon.hit(*this, target);
}

std::ostream& operator<<(std::ostream& out, const BaseEnemy& e) {
    out << "Enemy at position (" << e.pos_x << ", " << e.pos_y
        << ") with weapon " << e.weapon << "\n";
    return out;
}