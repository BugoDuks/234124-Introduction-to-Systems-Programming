#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include <string>
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include "../Players/Fighter.h"


class Barfight : public Card
{
public:
	/*
	* The creator of Barfight class
	* @return
	*	a new instance of Barfight
	*/
	Barfight();

	/*
	* Applies the actions of Barfight on the player
	* 
	* @param player - The player.
    * @return
    *      void
	*/
	void applyEncounter(Player &player) const override;

	/*
	*  Returns a new  pointer to card
	*
	*  @return
	 *      New card pointer of the card
	*/
	Card *clone() override;

	/*
	 * Returns the name of the card
	 *
	 * @return
	 *      string with the name of the card
	*/
	std::string getName() const override;

	/*
	* Explicitly telling the compiler to use the default methods
	*/
	Barfight(const Barfight &) = default;
	~Barfight() = default;
	Barfight &operator=(const Barfight & other) = default;

private:
	static const int DAMAGE_AMOUNT = 10;
};

#endif //EX4_BARFIGHT_H