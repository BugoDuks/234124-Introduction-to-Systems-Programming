#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>

class Player
{
public:
    /*
     * Creators of Player class
     *
     * @param name - The name of the player.
     * @param hitPoints - The amount of health a player receives, 100 by default.
     * @param force - The force of the player, 5 by default.
     * @return
     *      A new instance of Player.
    */
    Player(const char* name, const int health = DEFAULT_HEALTH, const int force = DEFAULT_FORCE);

    /*
     * Prints the player info to stream
    */
    void printInfo() const;

    /*
     * Levels up the player by 1
    */
    void levelUp();

    /*
     * Returns the level of the player
     *
     * @return
     *      Level of the player
    */
    int getLevel() const;

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
    void heal(const int amount);

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
    void addCoins(const int amount);

    /*
     * Reduces to the player's coins by a given amount
     *
     * @param amount - the amount to subtract.
     * @return
     *      False if there are no sufficient coins, True if successful
    */
    bool pay(const int amount);

    /*
     * Combines the level and force of the player and returns it
     *
     * @return
     *      total attack strength
    */
    int getAttackStrength() const;

    /*
     * Explicitly telling the compiler to use the default methods
    */
    Player(const Player &) = default;
    ~Player() = default;
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
    static const int MAX_LEVEL = 10;
    
};

#endif //EX2_PLAYER_H
