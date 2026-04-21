cmake_minimum_required(VERSION 4.0)
project(_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(_2
        main.cpp
        Weapon.h
        BaseCharacter.h
        Weapon.cpp
        GameExceptions.h
        BaseCharacter.cpp
        BaseEnemy.h
        BaseEnemy.cpp
        MainHero.h
        MainHero.cpp)
