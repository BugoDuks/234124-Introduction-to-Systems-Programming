//
// Created by bugod on 07/06/2022.
//

#include "Wizard.h"

std::string Wizard::getRole() const
{
    return "Wizard";
}

void Wizard::heal(const int amount)
{
    Player::heal(2 * amount);
}

Player *Wizard::clone(const std::string &name)
{
    return new Wizard(name);
}

Wizard::Wizard(const std::string &name) : Player(name) {}