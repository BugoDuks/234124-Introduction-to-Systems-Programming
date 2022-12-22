#ifndef EX4_GANG_H
#define EX4_GANG_H

#include <string>
#include <deque>
#include <memory>
#include "../utilities.h"
#include "Card.h"
#include "Battlecard.h"
#include "../Players/Player.h"

class Gang : public BattleCard
{
public:
	/*
	* The creator of Gang class
	* @return
	*	a new instance of Gang
	*/
	Gang();

    /*
    * The copy creator of Gang class
    * @return
    *	a new instance of Gang
    */
    Gang(const Gang &other);

    /*
    * The assignment operator of Gang class
    * @return
    *	a new instance of Gang
    */
    Gang &operator=(const Gang &other);

    /*
	* adds a new monster to the gang
     * @param monster - a unique pointer of the monster to be added
	*
	*/
    void addMonster(std::unique_ptr<BattleCard> monster);

	/*
	* Applies the actions of Gang on the player
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
     * Prints the card's info to stream
     *
     * @param os - a stream in which the datat will be outputed.
     * @return
     *      void
    */
    void printInfo(std::ostream &os) const override;



	/*
	* Explicitly telling the compiler to use the default methods
	*/

	~Gang() = default;


private:
    std::deque<std::unique_ptr<BattleCard>> m_theGang;

    static const int NO_VALUE = -2;
    static const int LEVEL_DOWN = -1;

};

#endif //EX4_GANG_H