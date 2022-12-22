#include "Gang.h"

Gang::Gang() : BattleCard(NO_VALUE, NO_VALUE, NO_VALUE, false), m_theGang() {}

std::string Gang::getName() const
{
	return "Gang";
}

Gang::Gang(const Gang & other) : BattleCard(NO_VALUE, NO_VALUE, NO_VALUE, false), m_theGang()
{
    for (const std::unique_ptr<BattleCard>& monster : other.m_theGang)
    {
        m_theGang.push_back(std::move(std::unique_ptr<BattleCard>(dynamic_cast<BattleCard*>(monster->clone()))));
    }
}

Gang &Gang::operator=(const Gang &other)
{
    m_theGang.clear();
    for (const std::unique_ptr<BattleCard>& monster : other.m_theGang)
    {
        m_theGang.push_back(std::move(std::unique_ptr<BattleCard>(dynamic_cast<BattleCard*>(monster->clone()))));
    }
    return *this;
}

void Gang::applyEncounter(Player &player) const
{
    bool lost = false;
    for (const std::unique_ptr<BattleCard>& monster : m_theGang)
    {
        if (lost)
        {
            monster->applyConsequences(player, false);
            printLossBattle(player.getName(), monster->getName());
        }
        else
        {
            if (!monster->applyFight(player))
            {
                printLossBattle(player.getName(), monster->getName());
                lost = true;
            }
            monster->applyConsequences(player, !lost);
        }
    }
    if (!lost)
    {
        printWinBattle(player.getName(), getName());
        player.levelUp();
    }
}

bool Gang::applyFight(Player &player) const
{
    for (const std::unique_ptr<BattleCard>& monster : m_theGang)
    {
        if (!monster->applyFight(player))
        {
            return false;
        }
    }
    return true;
}

void Gang::applyConsequences(Player &player, bool won) const
{
    for (const std::unique_ptr<BattleCard>& monster : m_theGang)
    {
        monster->applyConsequences(player, won);
    }
}

void Gang::printInfo(std::ostream &os) const
{
    os << "Gang Fight! " << std::endl;
    os << "There are " << m_theGang.size() << " monsters to fight:" << std::endl;
    for (const std::unique_ptr<BattleCard>& monster : m_theGang)
    {
        os << *monster << std::endl;
    }
}

void Gang::addMonster(std::unique_ptr<BattleCard> monster)
{
    m_theGang.push_back(std::move(monster));
}

BattleCard *Gang::clone()
{
    return new Gang();
}

