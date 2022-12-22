#ifndef EX4_CARD_H
#define EX4_CARD_H


#include <string>
#include "../Players/Player.h"
#include "../utilities.h"


class Card {
public:
    /*
    * The creator of Card class
    * 
    * @param name - The name of the card.
    * @return
    *	a new instance of Card
    */
    Card();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player &player) const = 0;

    /*
     * Prints the card's info to stream
     *
     * @param os - a stream in which the datat will be outputed.
     * @return
     *      void
    */
    virtual void printInfo(std::ostream &os) const;

    /*
     * Returns the name of the card
     *
     * @return
     *      string with the name of the card 
    */
    virtual std::string getName() const = 0;

    /*
    *  Returns a new  pointer to card
    * 
    *  @return
     *      New card pointer of the card
    */
    virtual Card *clone() = 0;

    /*
     * Explicitly telling the compiler to use the default methods
    */
    Card(const Card &) = default;
    virtual ~Card() = default;
    Card &operator=(const Card &other) = default;

};

/*
* Overload for the << operator to use with card
*/
std::ostream &operator<<(std::ostream &os, const Card &card);

#endif //EX4_CARD_H
