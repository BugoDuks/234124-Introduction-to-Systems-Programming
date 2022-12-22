#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>


class Player
{
public:
    /*
     * Creators of Player class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const std::string &name);

    /*
     * Prints the player info to stream
     *
     * @param os - the output steam to print into
    */
    void printInfo(std::ostream &os) const;

    /*
     * Levels up the player by 1
    */
    void levelUp(int amount = 1);


    /*
     * Adds to the player's force by a given amount
     *
     * @param amount - the amount to add.
    */
    void buff(const int amount);

    /*
     * Adds to the player's health by a given amount
     *
     * @param amount - the amount to add.
    */
     virtual void heal(const int amount);

    /*
     * Reduces to the player's health by a given amount
     *
     * @param amount - the amount to subtract.
    */
    void damage(const int amount);

    /*
     * Returns a boolean of the player's knocked out status
     *
     * @return
     *      True if knocked, else false
    */
    bool isKnockedOut() const;

    /*
     * Adds to the player's coins by a given amount
     *
     * @param amount - the amount to add.
    */
    virtual void addCoins(const int amount);

    /*
     * Reduces to the player's coins by a given amount
     *
     * @param amount - the amount to subtract.
     * @return
     *      False if there are no sufficient coins, True if successful
    */
    bool pay(const int amount);

    /*
    *  Returns a new pointer to player
    *
    *  @return
     *      New card pointer of the player
    */
    virtual Player *clone(const std::string& name) = 0;


    /* ----------------------------< Getters and Setters >---------------------------------- */

    /*
    * Returns the level of the player
    *
    * @return
    *      Level of the player
    */
    int getLevel() const;

    /*
    * Returns the Name of the player
    *
    * @return
    *      Name of the player
    */
    std::string getName() const;

    /*
    * Returns the Health of the player
    *
    * @return
    *      Health of the player
    */
    int getHealth() const;

    /*
    * Returns the amount of Coins of the player
    *
    * @return
    *      The amount of Coins of the player
    */
    int getCoins() const;


    /*
     * Combines the level and force of the player and returns it
     *
     * @return
     *      total attack strength
    */
    virtual int getAttackStrength() const;


    /*
     * return the player's class
     *
     * @return
     *     The player's class
    */
    virtual std::string getRole() const = 0;

    /* ---------------------------------------------------------------------------------------------- */

    /*
     * Explicitly telling the compiler to use the default methods
    */
    Player(const Player &) = default;
    virtual ~Player() = default;
    Player &operator=(const Player &other) = default;

private:
    std::string m_name;

    int m_maxHP;
    int m_health;

    int m_force;
    int m_level;
    int m_coins;

    static const int DEFAULT_HEALTH = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;
    static const int DEFAULT_LEVEL = 1;
    static const int MAX_LEVEL = 10;



};


    /*
     * Prints the players details according to printPlayerDetails().
     *
     * @param os - the ostream.
     * @param player - the player.
     * @return
     *      ostream reference
    */
    std::ostream& operator<<(std::ostream &os,const Player &player);


#endif //EX4_PLAYER_H
