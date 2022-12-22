#include "Treasure.h"

Treasure::Treasure() : Card() {}

void Treasure::applyEncounter(Player &player) const
{
	player.addCoins(TREASURE_AMOUNT);
	printTreasureMessage();
}

std::string Treasure::getName() const
{
	return "Treasure";
}

Card *Treasure::clone()
{
	return new Treasure();
}