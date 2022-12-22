#include "Barfight.h"

Barfight::Barfight() : Card() {}

void Barfight::applyEncounter(Player &player) const
{
	bool isFighter = true;
	Fighter *ptr = dynamic_cast<Fighter *>(&player);
	if (ptr == nullptr) 
	{
		isFighter = false;
	}

	if (!isFighter)
	{
		player.damage(DAMAGE_AMOUNT);
	}
	printBarfightMessage(isFighter);
}


std::string Barfight::getName() const
{
	return "Barfight";
}


Card *Barfight::clone()
{
	return new Barfight();
}
