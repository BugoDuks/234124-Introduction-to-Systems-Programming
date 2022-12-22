#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "../utilities.h"
#include "Card.h"
#include "../Players/Player.h"


class Treasure : public Card
{
public:
	/*
	* The creator of Treasure class
	* @return
	*	a new instance of Treasure
	*/
	Treasure();

	/*
	* Applies the actions of Treasure on the player
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
	* 
	* @param player - The player.
    * @return
    *      void
	*/
	Treasure(const Treasure &) = default;
	~Treasure() = default;
	Treasure &operator=(const Treasure & other) = default;

private:
	static const int TREASURE_AMOUNT = 10;
};

#endif //EX4_TREASURE_H