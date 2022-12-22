#include "Dragon.h"

Dragon::Dragon() : BattleCard(STRENGTH, LOSS_DAMAGE, LOOT, true) {}

void Dragon::applyEncounter(Player &player) const
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

bool Dragon::applyFight(Player &player) const
{
    return (player.getAttackStrength() >= STRENGTH);
}

void Dragon::applyConsequences(Player &player, bool won) const
{
    if (won)
    {
        player.addCoins(LOOT);
    }
    else
    {
        player.damage(player.getHealth());
    }
}


std::string Dragon::getName() const
{
	return "Dragon";
}


BattleCard *Dragon::clone()
{
	return new Dragon();
}