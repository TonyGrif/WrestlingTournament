#include "../headers/Team.h"

std::default_random_engine Team::eng = std::default_random_engine(time(NULL));

Team::Team()
    : teamID(TEAM_ID_NUMBER)
{
    this->numOfWrestlers = 0;
    std::normal_distribution<> ndist(35, 8);
    ndist(eng);

    for(int x = 0; x < ndist(eng); x++) {
        Wrestler* wrestler = new Wrestler(this->teamID + this->numOfWrestlers);
        this->AddWrestler(*wrestler);
        delete wrestler;
    }

    TEAM_ID_NUMBER += 100;
}

void Team::AddWrestler(Wrestler w)
{
    this->numOfWrestlers++;
}

void Team::InitializeVector()
{
    weightClasses.push_back(*new WeightClass(95, 100));
    weightClasses.push_back(*new WeightClass(101, 106));
}