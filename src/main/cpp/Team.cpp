#include "../headers/Team.h"

std::default_random_engine Team::eng = std::default_random_engine(time(NULL));

Team::Team()
{
    std::normal_distribution<> ndist(35, 8);
    ndist(eng);

    for(int x = 0; x < ndist(eng); x++) {

    }
}

void Team::InitializeVector()
{
    weightClasses.push_back(*new WeightClass(95, 100));
    weightClasses.push_back(*new WeightClass(101, 106));
}