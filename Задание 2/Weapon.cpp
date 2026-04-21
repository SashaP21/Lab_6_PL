#include "Weapon.h"
#include "GameExceptions.h"
#include "BaseCharacter.h"
#include <iostream>
#include <limits>

using std::cout;

Weapon::Weapon(const std::string& name, double damage, double range) {
    if (name.empty())
        throw InvalidWeaponData("Name cannot be empty");
    if (damage < 0)
        throw InvalidWeaponData("Damage cannot be negative");
    if (range < 0)
        throw InvalidWeaponData("Range cannot be negative");
    this->name = name;
    this->damage = damage;
    this->range = range;
}

void Weapon::hit(const BaseCharacter &actor, BaseCharacter &target) const {
    if (!target.is_alive()) {
        cout << "Enemy is already defeated\n";
    }
    else if (distance(actor, target) > range) {
        cout << "Enemy is too far for weapon " << name << "\n";
    }
    else {
        cout << "Dealt " << damage << " damage by weapon " << name << "\n";
        target.get_damage(damage);
    }
}

std::ostream& operator<<(std::ostream& out, const Weapon& w) {
    out << w.name << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Weapon& w) {
    std::string name;
    double damage;
    double range;
    while (true) {
        try {
            cout << "Enter weapon name: ";
            getline(in, name);
            cout << "Enter damage: ";
            in >> damage;
            cout << "Enter range: ";
            in >> range;
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            w = Weapon(name, damage, range);
            break;
        }
        catch (const InvalidWeaponData& e) {
            cout << e.what() << "\n";
        }
    }
    return in;
}