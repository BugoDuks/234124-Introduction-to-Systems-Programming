#include "Vampire.h"

Vampire::Vampire() : BattleCard(STRENGTH, LOSS_DAMAGE, LOOT, false) {}

void Vampire::applyEncounter(Player &player) const
{
    bool won = applyFight(player);
    applyConsequences(player, won);
    if (won)
    {
        printWinBattle(player.getName(), getName());
        player.levelUp();
    }
    else
    {
        printLossBattle(player.getName(), getName());
    }
}

bool Vampire::applyFight(Player &player) const
{
    return (player.getAttackStrength() >= STRENGTH);
}

void Vampire::applyConsequences(Player &player, bool won) const
{
    if (won)
    {
        player.addCoins(LOOT);
    }
    else
    {
        player.damage(LOSS_DAMAGE);
        player.buff(VAMPIRE_DEBUFF);
    }
}

std::string Vampire::getName() const
{
	return "Vampire";
}

BattleCard *Vampire::clone()
{
	return new Vampire();
}