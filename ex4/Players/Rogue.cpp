//
// Created by bugod on 07/06/2022.
//

#include "Rogue.h"

std::string Rogue::getRole() const
{
    return "Rogue";
}

void Rogue::addCoins(const int amount)
{
    Player::addCoins(2 * amount);
}

Player *Rogue::clone(const std::string &name)
{
    return new Rogue(name);
}

Rogue::Rogue(const std::string &name) : Player(name) {}