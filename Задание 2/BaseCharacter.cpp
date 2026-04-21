#include "BaseCharacter.h"
#include <cmath>
#include "GameExceptions.h"

BaseCharacter::BaseCharacter(double pos_x, double pos_y, double hp) {
    if (hp < 0)
        throw InvalidCharacterData("Hp cannot be negative");
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->hp = hp;
}

double BaseCharacter::get_x() const {
    return pos_x;
}

double BaseCharacter::get_y() const {
    return pos_y;
}

double BaseCharacter::get_hp() const {
    return hp;
}

double distance(const BaseCharacter &c1, const BaseCharacter &c2) {
    double dx = c1.get_x() - c2.get_x();
    double dy = c1.get_y() - c2.get_y();
    return sqrt(dx * dx + dy * dy);
}

bool BaseCharacter::is_alive() const {
    return hp > 0;
}

void BaseCharacter::get_damage(double amount) {
    hp -= amount;
    if (hp < 0)
        hp = 0;
}

void BaseCharacter::move(double delta_x, double delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
}