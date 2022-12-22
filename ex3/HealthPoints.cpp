#include "HealthPoints.h"

HealthPoints::HealthPoints(int amount)
{
	if (amount <= 0)
	{
		throw HealthPoints::InvalidArgument();
	}
	m_maxPoints = amount;
	m_points = amount;
}

void HealthPoints::applyBoundaries()
{
    if (m_points > m_maxPoints)
    {
        m_points = m_maxPoints;
    }
    if (m_points < 0)
    {
        m_points = 0;
    }
}


HealthPoints &HealthPoints::operator+=(const int amount)
{
	m_points += amount;
    this->applyBoundaries();
    return *this;
}


HealthPoints &HealthPoints::operator-=(const int amount)
{
    return *this += (-amount);
}

/*
* ---------------------------= Independent function definitionstions =-----------------------------
*/

bool operator==(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return (hp1.m_points == hp2.m_points);
}

bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return !(hp1 == hp2);
}

bool operator>(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return (hp1.m_points > hp2.m_points);
}

bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return (hp1 > hp2) || (hp1 == hp2);
}

bool operator<(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return (hp2 > hp1);
}

bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2)
{
	return (hp2 >= hp1);
}

HealthPoints operator+(const HealthPoints& hp, int num)
{
    HealthPoints result = hp;
    result += num;
    return result;
}

HealthPoints operator+(int num, const HealthPoints& hp)
{
    return (hp + num);
}

HealthPoints operator-(const HealthPoints& hp, int num)
{
    return (hp + (-num));
}


std::ostream& operator<<(std::ostream& os, const HealthPoints &hp)
{
    return os << hp.m_points << "(" << hp.m_maxPoints << ")" ;
}
