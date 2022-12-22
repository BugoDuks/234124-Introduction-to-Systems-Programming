//
// Created by bugod on 07/06/2022.
//

#include "Fighter.h"



std::string Fighter::getRole() const
{
    return "Fighter";
}

int Fighter::getAttackStrength() const
{
    return 2*(Player::getAttackStrength()) - getLevel();
}

Player *Fighter::clone(const std::string& name)
{
    return new Fighter(name);
}

Fighter::Fighter(const std::string &name) : Player(name) {}