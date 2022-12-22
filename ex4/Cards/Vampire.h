#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include <string>
#include "../utilities.h"
#include "Card.h"
#include "Battlecard.h"
#include "../Players/Player.h"

class Vampire : public BattleCard
{
public:
	/*
	* The creator of Vampire class
	* @return
	*	a new instance of Vampire
	*/
	Vampire();

	/*
	* Applies the actions of Vampire on the player
	*
	* @param player - The player.
	* @return
	*      void
	*/
	void applyEncounter(Player &player) const override;

    /*
    * Handling the player's fight with the monster:
    *
    * @param player - The player.
    * @return
    *      true - if the player won.
    *      false - if the player lost.
    */
    bool applyFight(Player &player) const override;

    /*
    * Applying the card's consequences at loss.
    *
    * @param player - The player.
    * @return
    *      void
    */
    void applyConsequences(Player &player, bool won) const override;

	/*
	*  Returns a new  pointer to card
	*
	*  @return
	 *      New card pointer of the card
	*/
	BattleCard *clone() override;


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
	Vampire(const Vampire &) = default;
	~Vampire() = default;
	Vampire &operator=(const Vampire & other) = default;

private:
	static const int STRENGTH = 10;
	static const int LOOT = 2;
	static const int LOSS_DAMAGE = 10;
	static const int VAMPIRE_DEBUFF = -1;
};

#endif //EX4_VAMPIRE_H
