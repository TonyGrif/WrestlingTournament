#include "../headers/Team.h"

std::default_random_engine Team::eng = std::default_random_engine(time(NULL));

Team::Team()
    : teamID(TEAM_ID_NUMBER)
{
    std::normal_distribution<> ndist(35, 8);
    ndist(eng);

    for(int x = 0; x < ndist(eng); x++) {

    }

    TEAM_ID_NUMBER += 100;
}

void Team::AddWrestler(Wrestler w)
{
    
}

void Team::InitializeVector()
{
    weightClasses.push_back(*new WeightClass(95, 100));
    weightClasses.push_back(*new WeightClass(101, 106));
}