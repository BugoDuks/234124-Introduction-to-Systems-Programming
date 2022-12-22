
#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue : public Player
{
public:
    /*
    * Creators of Rogue class
    *
    * @param name - The name of the player.
    * @return
    *      A new instance of Rogue.
    */
    explicit Rogue(const std::string &name);

    /*
     * give the player's class
     *
     * @return
     *     The player's class
    */
    std::string getRole() const override;

    /*
     * Adds to the player's coins by 2 times a given amount (because it's a Rogue)
     *
     * @param amount - the amount to add.
    */
     void addCoins(const int amount) override;

     /*
    *  Returns a new pointer to player
    *
    *  @return
     *      New card pointer of the player
    */
     Player *clone(const std::string &name) override;

    /*
     * Explicitly telling the compiler to use the default methods
    */
    Rogue(const Rogue &) = default;
    ~Rogue() override = default;
    Rogue &operator=(const Rogue &other) = default;


};


#endif //EX4_ROGUE_H
