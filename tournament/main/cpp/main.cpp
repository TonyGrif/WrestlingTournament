#include <iostream>

#include "../headers/Tournament.h"

int main()
{
    Tournament firstRounds[8];
    std::list<Team> winners;

    for(int x = 0; x < 8; x++)
    {
        winners.push_back(*firstRounds[x].ConductTournament());
    }

    for(auto i : winners)
    {
        std::cout << i.TeamID() << " advances with " << i.CurrentScore() 
            << " points (" << i.GetWins() << "/" << i.GetLosses() << ")" << std::endl;
        i.ResetScore();
    }
    std::cout << std::endl;

    Tournament finalRound(winners);

    Team *finalWinner = finalRound.ConductTournament();
    std::cout << finalWinner->TeamID() << " wins with " << finalWinner->CurrentScore()
        << " points and a total W/L ratio of " << finalWinner->GetWins() << "/" << 
        finalWinner->GetLosses() << "!" << std::endl;

    return 0;
}