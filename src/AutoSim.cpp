#include "AutoSim.hpp"

AutoSim::AutoSim(int)
{
}

AutoSim::AutoSim(std::vector<std::string>)
{
}

std::vector<Player*> AutoSim::getPlayers()
{
	return std::vector<Player*>();
}

Board* AutoSim::getBoard()
{
	return nullptr;
}

TurnTuple AutoSim::takeTurn()
{
	return TurnTuple(nullptr, 0);
}

Player* AutoSim::nextPlayer()
{
	return nullptr;
}
