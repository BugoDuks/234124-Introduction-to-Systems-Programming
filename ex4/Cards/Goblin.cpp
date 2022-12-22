#include "Goblin.h"

Goblin::Goblin() : BattleCard(STRENGTH, LOSS_DAMAGE, LOOT, false) {}

void Goblin::applyEncounter(Player &player) const
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

bool Goblin::applyFight(Player &player) const
{
    return (player.getAttackStrength() >= STRENGTH);
}

void Goblin::applyConsequences(Player &player, bool won) const
{
    if (won)
    {
        player.addCoins(LOOT);
    }
    else
    {
        player.damage(LOSS_DAMAGE);
    }
}

std::string Goblin::getName() const
{
	return "Goblin";
}

BattleCard *Goblin::clone()
{
	return new Goblin();
}