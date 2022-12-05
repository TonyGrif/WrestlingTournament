#include "../headers/Tournament.h"

std::default_random_engine Tournament::boutEng = std::default_random_engine(time(NULL));

Tournament::Tournament()
{
    for(int x = 0; x < 8; x++)
    {
        this->Teams.push_back(*new Team);
    }
}

void Tournament::ConductMatch(Team one, Team two)
{
    // Must have the same number of weight class to work.
    for(int x = 0; x < one.GetNumberOfWeightClasses(); x++)
    {
        int score = this->ConductBout(one.GetWrestlersAt(x)->top(), two.GetWrestlersAt(x)->top());


    }
}

int Tournament::ConductBout(Wrestler one, Wrestler two)
{
    int abilityOne = one.Ability();
    int abilityTwo = two.Ability();

    std::normal_distribution<float> oneDist(abilityOne, 15);
    std::normal_distribution<float> twoDist(abilityTwo, 15);

    // Quick throw away to ensure better randomness
    oneDist(boutEng);

    int scoreOne = oneDist(boutEng);
    int scoreTwo = twoDist(boutEng);

    return scoreOne - scoreTwo;
}

void Tournament::AdjustRecord(int score, Team winner, Team loser, int winningID, int loosingID)
{
    if(0 <= score < 4)
    {

    }
    else if(4 <= score < 8)
    {

    }
    else if(8 <= score < 12)
    {

    }
    else
    {

    }
    
    winner.IncrementWins(loosingID);
    loser.IncrementLosses(winningID);
}