#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include <string>
#include <iostream>
#include "../utilities.h"
#include "Card.h"
#include "../Players/Player.h"

class Merchant : public Card
{
public:
	/*
	* The creator of Merchant class
	* @return
	*	a new instance of Merchant
	*/
	Merchant();

	/*
	* Applies the actions of Merchant on the player
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
	Merchant(const Merchant &) = default;
	~Merchant() = default;
	Merchant &operator=(const Merchant & other) = default;

private:
	static const int POTION_OPTION = 1;
	static const int POTION_COST = 5;
	static const int BOOST_OPTION = 2;
	static const int BOOST_COST = 10;
	static const int AMOUNT_TO_ADD = 1;
};

#endif //EX4_MERCHANT_H