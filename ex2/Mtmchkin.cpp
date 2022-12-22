#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
    m_player(playerName),
    m_deck(new Card[(numOfCards>0 && cardsArray) ? numOfCards : 1]),
    m_numOfCards(numOfCards),
    m_currentCard(0),
    m_status(GameStatus::MidGame)
{
    if (numOfCards>0 && cardsArray)
    {
        for (int i = 0 ; i < numOfCards ; ++i)
        {
            m_deck[i] = cardsArray[i];
        }
    }
    else
    {
        m_numOfCards = 1;
    }
}

Mtmchkin::Mtmchkin(const char *playerName) :
        m_player(playerName),
        m_deck(new Card[1]),
        m_numOfCards(1),
        m_currentCard(0),
        m_status(GameStatus::MidGame)
{}

Mtmchkin::Mtmchkin(const Card *cardsArray, int numOfCards) :
        m_player(""),
        m_deck(new Card[(numOfCards>0 && cardsArray) ? numOfCards : 1]),
        m_numOfCards(numOfCards),
        m_currentCard(0),
        m_status(GameStatus::MidGame)
{
    if (numOfCards>0 && cardsArray)
    {
        for (int i = 0 ; i < numOfCards ; ++i)
        {
            m_deck[i] = cardsArray[i];
        }
    }
    else
    {
        m_numOfCards = 1;
    }
}

Mtmchkin::Mtmchkin(const Mtmchkin &other) :
    m_player(other.m_player),
    m_deck(new Card[other.m_numOfCards]),
    m_numOfCards(other.m_numOfCards),
    m_currentCard(other.m_currentCard),
    m_status(other.m_status)
{
    for (int i = 0 ; i < m_numOfCards ; ++i)
    {
        m_deck[i] = other.m_deck[i];
    }
}

Mtmchkin &Mtmchkin::operator=(const Mtmchkin &other)
{
    m_player = other.m_player;
    m_numOfCards = other.m_numOfCards;
    m_currentCard = other.m_currentCard;
    m_status = other.m_status;
    if (m_deck != other.m_deck)
    {
        Card* toDelete = m_deck;
        m_deck = new Card[m_numOfCards];
        for (int i = 0 ; i < m_numOfCards ; ++i)
        {
            m_deck[i] = other.m_deck[i];
        }
        delete[] toDelete;
    }
    return *this;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_deck;
}

void Mtmchkin::playNextCard()
{
    Card currentCard = m_deck[m_currentCard];
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
    m_player.printInfo();

    ++m_currentCard;
    if (m_currentCard >= m_numOfCards)
    {
        m_currentCard = 0;
    }

    if (m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    else if (m_player.getLevel() == WIN_LEVEL)
    {
        m_status = GameStatus::Win;
    }
}

bool Mtmchkin::isOver() const
{
    return m_player.getLevel() == WIN_LEVEL || m_player.isKnockedOut();
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}
