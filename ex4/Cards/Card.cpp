#include "Card.h"

Card::Card() {}

void Card::printInfo(std::ostream &os) const
{
	printCardDetails(os, getName());
	printEndOfCardDetails(os);
}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
	card.printInfo(os);
	return os;
}
