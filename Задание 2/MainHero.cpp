#include "MainHero.h"
#include "GameExceptions.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

MainHero::MainHero(double pos_x, double pos_y, double hp, const std::string& name) : BaseCharacter(pos_x, pos_y) {
    if (name.empty())
        throw InvalidCharacterData("Name cannot be empty");
    if (hp < 0 || hp > 200)
        throw InvalidCharacterData("MainHero health should be in range from 0 to 200");
    this->name = name;
    this->hp = hp;
}

void MainHero::hit(BaseEnemy &target) const {
    if (inventory.empty())
        cout << "I am unarmed\n";
    else
        inventory[current_weapon_index].hit(*this, target);
}

void MainHero::add_weapon(const Weapon& weapon) {
    if (inventory.empty())
        current_weapon_index = 0;
    inventory.push_back(weapon);
    cout << "Picked up " << weapon << "\n";
}

void MainHero::next_weapon() {
    if (inventory.empty())
        cout << "I am unarmed\n";
    else if (inventory.size() == 1)
        cout << "I have only one weapon\n";
    else {
        current_weapon_index = (current_weapon_index + 1) % inventory.size();
        cout << "Switched weapon to " << inventory[current_weapon_index] << "\n";
    }
}

void MainHero::heal(double amount) {
    hp += amount;
    if (hp > 200)
        hp = 200;
    cout << "Healed, now health is " << hp << "\n";
}
