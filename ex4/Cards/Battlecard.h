#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include <string>
#include "../utilities.h"
#include "Card.h"
#include "../Players/Player.h"

class BattleCard : public Card
{
public:
	/*
	* The creator of Card class
	*
	* @param name - The name of the card.
	* @param force - The force of the card.
	* @param damage - The damage of the card.
	* @param coins - The coins of the card.
	* @param isDragon - The isDragon of the card.
	* @return
	*	a new instance of Card
	*/
	BattleCard(int force, int damage, int coins, bool isDragon);

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	virtual void applyEncounter(Player &player) const override = 0;

    /*
    * Handling the player's fight with the monster:
     *
     * @param player - The player.
     * @return
     *      true - if the player won.
     *      false - if the player lost.
    */
    virtual bool applyFight(Player &player) const = 0;


    /*
    * Applying the card's consequences at loss.
    *
    * @param player - The player.
    * @return
    *      void
    */
    virtual void applyConsequences(Player &player, bool won) const = 0;

	/*
	 * Prints the card's info to stream
	 *
	 * @param os - a stream in which the datat will be outputed.
	 * @return
	 *      void
	*/
	virtual void printInfo(std::ostream &os) const override;

	/*
	*  Returns a new  pointer to card
	*
	*  @return
	 *      New card pointer of the card
	*/
	virtual BattleCard *clone() = 0;

	/*
	 * Returns the name of the card
	 *
	 * @return
	 *      string with the name of the card
	*/
	virtual std::string getName() const = 0;

	/*
	 * Explicitly telling the compiler to use the default methods
	*/
	BattleCard(const BattleCard &) = default;
	virtual ~BattleCard() = default;
	BattleCard &operator=(const BattleCard & other) = default;

private:
	int m_force; 
	int m_damage; 
	int m_coins;
	bool m_isDragon;
};

#endif //EX4_BATTLECARD_H