#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include <string>
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include "../Players/Rogue.h"


class Pitfall : public Card
{
public:
	/*
	* The creator of Pitfall class
	* @return
	*	a new instance of Pitfall
	*/
	Pitfall();

	/*
	* Applies the actions of Pitfall on the player
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
	Pitfall(const Pitfall &) = default;
	~Pitfall() = default;
	Pitfall &operator=(const Pitfall & other) = default;

private:
	static const int DAMAGE_AMOUNT = 10;
};

#endif //EX4_PITFALL_H