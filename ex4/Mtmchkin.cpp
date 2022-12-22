#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const std::string &fileName) :
    m_deck(), 
    m_players(), 
    m_winners(), 
    m_losers(), 
    m_round(0)
{
    printStartGameMessage();
    generateDeck(fileName, m_deck);
    int playerAmount = playerAmountInput();
    playersInput(playerAmount, m_players);    
}

void Mtmchkin::generateDeck(const std::string &fileName, std::deque<std::unique_ptr<Card>> &deck)
{
    std::ifstream deckFile(fileName);
    if (!deckFile)
    {
        throw DeckFileNotFound();
    }

    std::string card;
    int line = 1;
    while (std::getline(deckFile, card))
    {
        if (MAP_STRING_TO_CARD.find(card) != MAP_STRING_TO_CARD.end())
        {
            if (card == "Gang")
            {
                deck.push_back(std::move(generateGang(deckFile, line)));
            }
            else
            {
                deck.push_back(std::move(std::unique_ptr<Card>(MAP_STRING_TO_CARD.at(card)->clone())));
            }
            ++line;
        }
        else
        {
            throw DeckFileFormatError(line);
        }
    }

    if (deck.size() < MINIMUN_CARDS)
    {
        throw DeckFileInvalidSize();
    }
}

std::unique_ptr<Card> Mtmchkin::generateGang(std::ifstream &deckFile, int &line)
{
    std::unique_ptr<Gang> gang(new Gang());
    std::string card;
    while (std::getline(deckFile, card))
    {
        ++line;
        if ( (MAP_STRING_TO_BATTLE_CARD.find(card) != MAP_STRING_TO_BATTLE_CARD.end()))
        {
            gang->addMonster(std::move(std::unique_ptr<BattleCard>(MAP_STRING_TO_BATTLE_CARD.at(card)->clone())));
        }
        else if (card == "EndGang")
        {
            return std::move(gang);
        }
        else
        {
            throw DeckFileFormatError(line);
        }
    }
    throw DeckFileFormatError(++line);
}

int Mtmchkin::playerAmountInput()
{

    std::string input;
    while (true)
    {
        printEnterTeamSizeMessage();
        std::getline(std::cin, input);
        if (input == "2" || input == "3" || input == "4" || input == "5" || input == "6")
        {
            return std::stoi(input);
        }
        printInvalidTeamSize();
    }
}

void Mtmchkin::playersInput(int playerAmount, std::deque<std::unique_ptr<Player>> &players)
{
    int playerCounter = 0;
    std::string input;
    std::string name, role;
    bool nextPlayer = true;
    while (playerCounter < playerAmount)
    {
        if (nextPlayer)
        {
            printInsertPlayerMessage();
        }
        nextPlayer = true;
        std::getline(std::cin, input);
        name = input.substr(0, input.find(' '));
        std::string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        bool notAlpha = (name.find_first_not_of(alpha) != std::string::npos);
        if (name.length() > MAX_NAME_LENGTH || name.length() <= 0 || notAlpha)
        {
            printInvalidName();
            nextPlayer = false;
            continue;
        }
        role = input.substr(input.find(' ') + 1, input.length());
        if (MAP_STRING_TO_PLAYER.find(role) != MAP_STRING_TO_PLAYER.end())
        {
            players.push_back(std::move(std::unique_ptr<Player>(MAP_STRING_TO_PLAYER.at(role)->clone(name))));
        }
        else
        {
            printInvalidClass();
            nextPlayer = false;
            continue;
        }
        playerCounter++;

    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(++m_round);
    int numOfPlayers = (int)m_players.size();
    for (int i = 0; i < numOfPlayers; ++i) {
        std::unique_ptr<Player> currentPlayer = std::move(m_players.front()) ;
        m_players.pop_front();
        printTurnStartMessage(currentPlayer->getName());

        std::unique_ptr<Card> currentCard = std::move(m_deck.front()) ;
        m_deck.pop_front();

        currentCard->applyEncounter(*currentPlayer);
        m_deck.push_back(std::move(currentCard));

        if (currentPlayer->getLevel() == WINNING_LEVEL)
        {
            m_winners.push_back(std::move(currentPlayer));
        }
        else if (currentPlayer->isKnockedOut())
        {
            m_losers.push_front(std::move(currentPlayer));
        }
        else
        {
            m_players.push_back(std::move(currentPlayer));
        }
    }

    if (isGameOver())
    {
        printGameEndMessage();
    }
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank = 0;
    for (const std::unique_ptr<Player>& player : m_winners)
    {
        printPlayerLeaderBoard(++rank, *player);
    }
    for (const std::unique_ptr<Player>& player : m_players)
    {
        printPlayerLeaderBoard(++rank, *player);
    }
    for (const std::unique_ptr<Player>& player : m_losers)
    {
        printPlayerLeaderBoard(++rank, *player);
    }

}

bool Mtmchkin::isGameOver() const
{
    return (m_players.empty());
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_round;
}

