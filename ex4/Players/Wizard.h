
#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard :public Player
{
public:
    /*
    * Creators of Wizard class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Wizard.
    */
    explicit Wizard(const std::string &name);

    /*
     * give the player's class
     *
     * @return
     *     The player's class
    */
    std::string getRole() const override;

    /*
     * Adds to the player's health by 2 times a given amount (because it's a Wizard)
    *
     * @param amount - the amount to add.
    */
    void heal(const int amount) override;

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
    Wizard(const Wizard &) = default;
    ~Wizard() override = default;
    Wizard &operator=(const Wizard &other) = default;


};


#endif //EX4_WIZARD_H
