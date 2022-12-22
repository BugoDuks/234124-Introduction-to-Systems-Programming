#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <deque>
#include <map>

#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"

#include "utilities.h"
#include "Exception.h"

class Mtmchkin
{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    /*
     * Here we are explicitly telling the compiler to use the default or deleted methods
    */
    Mtmchkin(const Mtmchkin &) = delete;
    ~Mtmchkin() = default;
    Mtmchkin &operator=(const Mtmchkin & other) = delete;


private:

    /*
    *  Generates the card deck from the provided file.
    *
    * @param filename - the name of the file
    * @param deck - a container of cards to fill
    */
    void generateDeck(const std::string &fileName, std::deque<std::unique_ptr<Card>> &deck);

    /*
    *  Generates Gang card from the provided file.
    * @param file - the file
    */
    std::unique_ptr<Card> generateGang(std::ifstream &deckFile, int &line);

    /*
    *  Gets input for the player amount, validates it and return the amount.
    *
    *  @return
    *          int - number of players
    */
    static int playerAmountInput();

    /*
    *  Gets input for the player names and role. 
    *  Validates the amount, names and roles and sets them.
    *
    */
    void playersInput(int playerAmount, std::deque<std::unique_ptr<Player>> &players);

    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    int m_round;

    std::map<std::string, std::shared_ptr<Card>> MAP_STRING_TO_CARD =
    {
            {"Barfight", std::shared_ptr<Card>(new Barfight())},
            {"Dragon", std::shared_ptr<Card>(new Dragon())},
            {"Fairy", std::shared_ptr<Card>(new Fairy())},
            {"Goblin", std::shared_ptr<Card>(new Goblin())},
            {"Merchant", std::shared_ptr<Card>(new Merchant())},
            {"Pitfall", std::shared_ptr<Card>(new Pitfall())},
            {"Treasure", std::shared_ptr<Card>(new Treasure())},
            {"Vampire", std::shared_ptr<Card>(new Vampire())},
            {"Gang", std::shared_ptr<Card>(new Gang())}
    };
    std::map<std::string, std::shared_ptr<Player>> MAP_STRING_TO_PLAYER =
    {
            {"Fighter", std::shared_ptr<Player>(new Fighter(""))},
            {"Rogue", std::shared_ptr<Player>(new Rogue(""))},
            {"Wizard", std::shared_ptr<Player>(new Wizard(""))}
    };
    std::map<std::string, std::shared_ptr<BattleCard>> MAP_STRING_TO_BATTLE_CARD =
    {
            {"Dragon", std::shared_ptr<BattleCard>(new Dragon())},
            {"Goblin", std::shared_ptr<BattleCard>(new Goblin())},
            {"Vampire", std::shared_ptr<BattleCard>(new Vampire())}
    };

    const static int NUM_OF_CARD_TYPES = 8;
    const static int WINNING_LEVEL = 10;
    const static int MINIMUN_CARDS = 5;
    const static int MAX_NAME_LENGTH = 15;
};



#endif /* MTMCHKIN_H_ */