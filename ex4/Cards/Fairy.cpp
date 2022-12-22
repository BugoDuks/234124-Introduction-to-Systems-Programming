#include "Fairy.h"

Fairy::Fairy() : Card() {}

void Fairy::applyEncounter(Player &player) const
{
	bool isWizard = true;
	Wizard *ptr = dynamic_cast<Wizard *>(&player);
	if (ptr == nullptr) 
	{
		isWizard = false;
	}

	if (isWizard)
	{
		player.heal(HEALTH_AMOUNT);
	}
	printFairyMessage(isWizard);
}

std::string Fairy::getName() const
{
	return "Fairy";
}

Card *Fairy::clone()
{
	return new Fairy();
}