
#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
public:
    /*
     * Creators of Fighter class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Fighter.
    */
    explicit Fighter(const std::string &name);

    /*
     * give the player's class
     *
     * @return
     *     The player's class
    */
    std::string getRole() const override;

    /*
     * Combines the level and 2 times the force of the player and returns it
     * (2 times the force because it's a Fighter)
     *
     * @return
     *      total attack strength
    */
    int getAttackStrength() const override;

    /*
    *  Returns a new pointer to player
    *
    *  @return
     *      New card pointer of the player
    */
    Player *clone(const std::string& name) override;

    /*
     * Explicitly telling the compiler to use the default methods
    */
    Fighter(const Fighter &) = default;
    ~Fighter() override = default;
    Fighter &operator=(const Fighter &other) = default;


};


#endif //EX4_FIGHTER_H
