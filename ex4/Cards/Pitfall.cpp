#include "Pitfall.h"

Pitfall::Pitfall() : Card() {}

void Pitfall::applyEncounter(Player &player) const
{
	bool isRogue = true;
	Rogue *ptr = dynamic_cast<Rogue *>(&player);
	if (ptr == nullptr)
	{
		isRogue = false;
	}

	if (!isRogue)
	{
		player.damage(DAMAGE_AMOUNT);
	}
	printPitfallMessage(isRogue);
}

std::string Pitfall::getName() const
{
	return "Pitfall";
}

Card *Pitfall::clone()
{
	return new Pitfall();
}