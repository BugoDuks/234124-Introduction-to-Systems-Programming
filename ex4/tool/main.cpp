#include "..\Exception.h"
#include "..\Mtmchkin.h"
#include <string>
#include <iostream>



int main() {

    const std::string deckFile = "deck.txt";
    const int MAX_ROUND = 100;

    try
    {
        Mtmchkin game(deckFile);
        while (!game.isGameOver())
        {
            if (game.getNumberOfRounds() > MAX_ROUND)
            {
                printGameEndMessage();
                break;
            }
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Something went wrong..." << std::endl;
    }

    return 0;
}

