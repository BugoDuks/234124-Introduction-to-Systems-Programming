#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include <string>
#include "../utilities.h"
#include "Card.h"
#include "Battlecard.h"
#include "../Players/Player.h"

class Goblin : public BattleCard
{
public:
	/*
	* The creator of Goblin class
	* @return
	*	a new instance of Goblin
	*/
	Goblin();

	/*
	* Applies the actions of Goblin on the player
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
	Goblin(const Goblin &) = default;
	~Goblin() = default;
	Goblin &operator=(const Goblin & other) = default;

private:
	static const int STRENGTH = 6;
	static const int LOOT = 2;
	static const int LOSS_DAMAGE = 10;
};

#endif //EX4_GOBLIN_H