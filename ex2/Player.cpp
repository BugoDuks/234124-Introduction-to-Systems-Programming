#include "Player.h"
#include "utilities.h"

Player::Player(const char* name, const int health, const int force) :
	m_name(name), 
	m_maxHP(health),
	m_health(health), 
	m_force(force), 
	m_level(1), 
	m_coins(0)
{
	if (m_maxHP <= 1)
	{
		m_maxHP = DEFAULT_HEALTH;
		m_health = DEFAULT_HEALTH;
	}
	if (m_force <= 1)
	{
		m_force = DEFAULT_FORCE;
	}
}

void Player::printInfo() const
{
	printPlayerInfo(m_name.c_str(), m_level, m_force, m_health, m_coins);
}

void Player::levelUp()
{
	if (m_level < MAX_LEVEL)
	{
		m_level++;
	}
}

int Player::getLevel() const
{
	return m_level;
}

void Player::buff(const int amount)
{
	if (amount > 0)
	{
		m_force += amount;
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


int Player::getAttackStrength() const
{
	return m_level + m_force;
}
