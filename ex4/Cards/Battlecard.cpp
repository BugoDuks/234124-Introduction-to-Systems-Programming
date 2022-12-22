#include "Battlecard.h"

BattleCard::BattleCard( int force, int damage, int coins, bool isDragon) :
	Card(),
	m_force(force),
	m_damage(damage),
	m_coins(coins),
	m_isDragon(isDragon)
	{}

void BattleCard::printInfo(std::ostream &os) const
{
	printCardDetails(os, getName());
	printMonsterDetails(os, m_force, m_damage, m_coins, m_isDragon);
	printEndOfCardDetails(os);
}