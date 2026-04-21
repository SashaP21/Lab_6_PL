#ifndef _2_GAMEEXCEPTIONS_H
#define _2_GAMEEXCEPTIONS_H
#include <stdexcept>

class InvalidWeaponData : public std::invalid_argument {
public:
    explicit InvalidWeaponData(const std::string& msg) : std::invalid_argument("InvalidWeaponData: " + msg) {};
};

class InvalidCharacterData : public std::invalid_argument {
public:
    explicit InvalidCharacterData(const std::string& msg) : std::invalid_argument("InvalidCharacterData: " + msg) {};
};

#endif //_2_GAMEEXCEPTIONS_H