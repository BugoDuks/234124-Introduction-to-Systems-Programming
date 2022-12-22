#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include <string>
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include "../Players/Wizard.h"


class Fairy : public Card
{
public:
	/*
	* The creator of Fairy class
	* @return
	*	a new instance of Fairy
	*/
	Fairy();

	/*
	* Applies the actions of Fairy on the player
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
	Fairy(const Fairy &) = default;
	~Fairy() = default;
	Fairy &operator=(const Fairy & other) = default;

private:
	static const int HEALTH_AMOUNT = 10;
};

#endif //EX4_FAIRY_H