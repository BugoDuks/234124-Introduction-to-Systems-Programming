#include "Merchant.h"

Merchant::Merchant() : Card() {}

void Merchant::applyEncounter(Player &player) const
{
	bool success = true;
	int cost = 0;
	std::string input;
	printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
	while (true)
	{
		try
		{
			std::getline(std::cin, input);
			if (input != "0" && input != "1" && input != "2")
			{
				throw std::logic_error("Bad input");
			}
		}
		catch (const std::logic_error &e)
		{
			printInvalidInput();
			continue;
		}

		break;
	}

	if (input == std::to_string(POTION_OPTION))
	{
		cost = POTION_COST;
		if (player.pay(cost))
		{
			player.heal(AMOUNT_TO_ADD);
		} 
		else
        {
            success = false;
        }
	}
	else if (input == std::to_string(BOOST_OPTION))
	{
		cost = BOOST_COST;
		if (player.pay(cost))
		{
			player.buff(AMOUNT_TO_ADD);
		} 
		else
        {
            success = false;
        }
	}

	if (!success)
	{
		cost = 0;
		printMerchantInsufficientCoins(std::cout);
	}

	printMerchantSummary(std::cout, player.getName(), std::stoi(input), cost);
}

std::string Merchant::getName() const
{
	return "Merchant";
}

Card *Merchant::clone()
{
	return new Merchant();
}
