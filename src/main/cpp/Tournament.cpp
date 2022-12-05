#include "../headers/Tournament.h"

std::default_random_engine Tournament::boutEng = std::default_random_engine(time(NULL));

Tournament::Tournament()
{
    for(int x = 0; x < 8; x++)
    {
        this->Teams.push_back(*new Team);
    }
}

void Tournament::ConductMatch(Team& one, Team& two)
{
    // Must have the same number of weight class to work.
    for(int x = 0; x < one.GetNumberOfWeightClasses(); x++)
    {
        const Wrestler* teamOneW = &one.GetWrestlersAt(x)->top();
        const Wrestler* teamTwoW = &two.GetWrestlersAt(x)->top();

        int score = this->ConductBout(*teamOneW, *teamTwoW);

        // Team 1 won
        if(score > 0) {
            this->AdjustRecord(score, one, two, teamOneW->ID(), teamTwoW->ID());
        }
        else if(score < 0) {
            score = abs(score);
            this->AdjustRecord(score, two, one, teamTwoW->ID(), teamOneW->ID());
        }
    }
}

int Tournament::ConductBout(Wrestler one, Wrestler two)
{
    int abilityOne = one.Ability();
    int abilityTwo = two.Ability();

    std::normal_distribution<> oneDist(abilityOne, 15);
    std::normal_distribution<> twoDist(abilityTwo, 15);

    // Quick throw away to ensure better randomness
    oneDist(boutEng);

    int scoreOne = oneDist(boutEng);
    int scoreTwo = twoDist(boutEng);

    return scoreOne - scoreTwo;
}

void Tournament::AdjustRecord(int score, Team& winner, Team& loser, int winningID, int loosingID)
{
    if(score >= 0 && score < 4)
    {
        winner.IncrementScore(3);
    }
    else if(score >= 4 && score < 8)
    {
        winner.IncrementScore(4);
    }
    else if(score >= 8 && score < 12)
    {
        winner.IncrementScore(5);
    }
    else
    {
        winner.IncrementScore(6);
    }
    
    winner.IncrementWins(loosingID);
    loser.IncrementLosses(winningID);
}