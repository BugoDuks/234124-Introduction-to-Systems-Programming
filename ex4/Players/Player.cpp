#include "Player.h"
#include "../utilities.h"


Player::Player(const std::string &name) :
        m_name(name),
        m_maxHP(DEFAULT_HEALTH),
        m_health(DEFAULT_HEALTH),
        m_force(DEFAULT_FORCE),
        m_level(DEFAULT_LEVEL),
        m_coins(DEFAULT_COINS) {}


void Player::printInfo(std::ostream &os) const
{
    printPlayerDetails(os, m_name, getRole(), m_level, m_force, m_health, m_coins);
}


void Player::levelUp(int amount)
    {
    if (m_level < MAX_LEVEL)
    {
        m_level += amount;
    }
}



void Player::buff(const int amount)
{
    m_force += amount;
    if (m_force < 0)
    {
        m_force = 0;
    }
}

void Player::heal(const int amount)
{
    if (amount > 0)
    {
        m_health += amount;
        if (m_health > m_maxHP)
        {
            m_health = m_maxHP;
        }
    }
}

void Player::damage(const int amount)
{
    if (amount > 0)
    {
        m_health -= amount;
        if (m_health < 0)
        {
            m_health = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    if (m_health)
    {
        return false;
    }
    return true;
}


void Player::addCoins(const int amount)
{
    if (amount > 0)
    {
        m_coins += amount;
    }
}


bool Player::pay(const int amount)
{
    if (amount < 0)
    {
        return true;
    }
    if (m_coins < amount)
    {
        return false;
    }
    m_coins -= amount;
    return true;
}



/* ----------------------------< Getters and Setters >---------------------------------- */

int Player::getLevel() const
{
    return m_level;
}

std::string Player::getName() const
{
    return m_name;
}

int Player::getHealth() const
{
    return m_health;
}

int Player::getCoins() const
{
    return m_coins;
}

int Player::getAttackStrength() const
{
    return m_level + m_force;
}

/* ---------------------------------------------------------------------------------------------- */

std::ostream& operator<<(std::ostream &os, const Player &player)
{
    player.printInfo(os);
    return os;
}