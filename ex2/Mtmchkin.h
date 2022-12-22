#ifndef EX2_GAME_H
#define EX2_GAME_H

#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus { Win, Loss, MidGame };

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards);

    /*
     * C'tor: that only gets a player name or no parameters.
     */
    Mtmchkin(const char *playerName = "");

    /*
     * C'tor: that doesn't get a player name.
     */
    Mtmchkin(const Card *cardsArray, int numOfCards);

    /*
     * copy C'tor:
     * @param other - the game needed to copy.
     * @return
     *    A new instance of Mtmchkin.
     */
    Mtmchkin(const Mtmchkin& other);


    /*
     * Assignment operator:
     * @param other - the game needed to copy.
     * @return
     *    Reference to Mtmchkin.
     */
    Mtmchkin &operator=(const Mtmchkin &other);


    /*
     *  D'tor
     */
    ~Mtmchkin();


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;


private:
    Player m_player;
    Card* m_deck;
    int m_numOfCards;
    int m_currentCard;
    GameStatus m_status;

    static const int WIN_LEVEL = 10;

};


#endif //EX2_GAME_H
