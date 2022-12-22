#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include <string>
#include "../utilities.h"
#include "Card.h"
#include "Battlecard.h"
#include "../Players/Player.h"

class Dragon : public BattleCard
{
public:
	/*
	* The creator of Dragon class
	* @return
	*	a new instance of Dragon
	*/
	Dragon();

	/*
	* Applies the actions of Dragon on the player
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
	Dragon(const Dragon &) = default;
	~Dragon() = default;
	Dragon &operator=(const Dragon & other) = default;

private:
	static const int STRENGTH = 25;
	static const int LOOT = 1000;
	static const int LOSS_DAMAGE = -1;
};

#endif //EX4_DRAGON_H