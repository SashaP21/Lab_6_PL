#include <iostream>
#include <vector>
#include <limits>
#include "BaseEnemy.h"
#include "MainHero.h"
#include "Weapon.h"
#include "GameExceptions.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showStatus(const MainHero& hero, const vector<BaseEnemy>& enemies) {
    cout << "\n=== Hero: (" << hero.get_x() << ", " << hero.get_y()
         << ") HP: " << hero.get_hp() << " ===\n";
    cout << "Enemies:\n";
    for (size_t i = 0; i < enemies.size(); ++i) {
        if (enemies[i].is_alive())
            cout << i + 1 << ". " << enemies[i];
        else
            cout << i + 1 << ". [DEFEATED]\n";
    }
    cout << endl;
}

int main() {
    cout << "===== EXCEPTION TESTING =====\n";

    try {
        Weapon w("", 10, 5);
    }
    catch (const InvalidWeaponData& e) {
        cout << e.what() << "\n";
    }

    try {
        Weapon w("Sword", -5, 5);
    }
    catch (const InvalidWeaponData& e) {
        cout << e.what() << "\n";
    }

    try {
        MainHero h(0,0,250,"Test");
    }
    catch (const InvalidCharacterData& e) {
        cout << e.what() << "\n";
    }

    try {
        MainHero h(0,0,100,"");
    }
    catch (const InvalidCharacterData& e) {
        cout << e.what() << "\n";
    }

    try {
        BaseCharacter c(0,0,-10);
    }
    catch (const InvalidCharacterData& e) {
        cout << e.what() << "\n";
    }

    cout << "\n===== OBJECT CREATION =====\n";

    Weapon sword("Steel Sword", 25, 3.0);
    Weapon bow("Long Bow", 15, 10.0);
    Weapon axe("Battle Axe", 40, 2.0);
    cout << "Weapons: " << sword << ", " << bow << ", " << axe << "\n";

    MainHero hero(0, 0, 150, "Arthur");
    hero.add_weapon(sword);
    hero.add_weapon(bow);
    hero.add_weapon(axe);
    hero.next_weapon();
    hero.heal(20);
    hero.move(2, 1);

    vector<BaseEnemy> enemies;
    enemies.emplace_back(5, 0, 50, Weapon("Club", 12, 4.0));
    enemies.emplace_back(10, 5, 80, Weapon("Spear", 18, 6.0));
    enemies.emplace_back(-3, 8, 40, Weapon("Dagger", 10, 2.0));

    cout << "\n===== BATTLE START =====\n";
    cout << "Controls:\n"
         << "1 - move\n"
         << "2 - attack enemy\n"
         << "3 - switch weapon\n"
         << "4 - heal (+20 HP)\n"
         << "0 - exit\n";

    while (hero.is_alive()) {
        bool anyAlive = false;
        for (const auto& e : enemies)
            if (e.is_alive()) {
                anyAlive = true;
                break;
            }
        if (!anyAlive) {
            cout << "\n*** ALL ENEMIES DEFEATED! VICTORY! ***\n";
            break;
        }

        showStatus(hero, enemies);
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        clearInput();

        if (choice == 0) {
            cout << "Exiting.\n";
            break;
        }

        switch (choice) {
        case 1: {
            double dx, dy;
            cout << "Offset X and Y: ";
            cin >> dx >> dy;
            clearInput();
            hero.move(dx, dy);
            break;
        }
        case 2: {
            cout << "Enemy number: ";
            size_t idx;
            cin >> idx;
            clearInput();
            if (idx < 1 || idx > enemies.size() || !enemies[idx-1].is_alive()) {
                cout << "Invalid choice.\n";
                break;
            }
            BaseEnemy& target = enemies[idx-1];
            hero.hit(target);

            if (target.is_alive() && hero.is_alive()) {
                cout << "Enemy counterattacks!\n";
                target.hit(hero);
            }
            break;
        }
        case 3:
            hero.next_weapon();
            break;
        case 4:
            hero.heal(20);
            break;
        default:
            cout << "Unknown command.\n";
            break;
        }

        if (!hero.is_alive()) {
            cout << "\n*** HERO HAS FALLEN... GAME OVER ***\n";
        }
    }
}