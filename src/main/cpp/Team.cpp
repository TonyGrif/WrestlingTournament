#include "../headers/Team.h"

std::default_random_engine Team::eng = std::default_random_engine(time(NULL));

Team::Team()
    : teamID(TEAM_ID_NUMBER)
{
    this->numOfWrestlers = 0;
    this->InitializeVector();

    std::normal_distribution<> ndist(35, 8);
    ndist(eng);

    for(int x = 0; x < ndist(eng); x++) {
        Wrestler* wrestler = new Wrestler(this->teamID + this->numOfWrestlers);
        this->AddWrestler(*wrestler);
        delete wrestler;
    }

    // Ensure every weight class has at least one wrestler
    for(int x = 0; x < this->GetNumberOfWeightClasses(); x++)
    {
        if(this->GetWrestlersAt(x)->size() == 0) {
            Wrestler* wrestler = new Wrestler(this->teamID + this->numOfWrestlers, 
                this->weightClasses[x].weight);
            this->AddWrestler(*wrestler);
            delete wrestler;
        }
    }

    this->currentScore = 0;

    TEAM_ID_NUMBER += 100;
}

void Team::AddWrestler(Wrestler w)
{
    int loc = this->FindWeightClass(w);
    w.Weight(this->weightClasses[loc].weight);
    this->weightClasses[loc].pq.push(w);

    this->numOfWrestlers++;
}

void Team::InitializeVector()
{
    weightClasses.push_back(*new WeightClass(100));
    weightClasses.push_back(*new WeightClass(106));
    weightClasses.push_back(*new WeightClass(113));
    weightClasses.push_back(*new WeightClass(120));
    weightClasses.push_back(*new WeightClass(126));
    weightClasses.push_back(*new WeightClass(132));
    weightClasses.push_back(*new WeightClass(138));
    weightClasses.push_back(*new WeightClass(145));
    weightClasses.push_back(*new WeightClass(152));
    weightClasses.push_back(*new WeightClass(160));
    weightClasses.push_back(*new WeightClass(170));
    weightClasses.push_back(*new WeightClass(182));
    weightClasses.push_back(*new WeightClass(195));
    weightClasses.push_back(*new WeightClass(220));
    weightClasses.push_back(*new WeightClass(285));
}

int Team::FindWeightClass(const Wrestler& w) const
{
    int distance = abs(w.Weight() - this->weightClasses[0].weight);

    for(int x = 1; x < this->GetNumberOfWeightClasses()+1; x++)
    {
        if(abs(w.Weight() - this->weightClasses[x].weight) > distance) {
            return x-1;
        }
        else {
            distance = abs(w.Weight() - this->weightClasses[x].weight);
        }
    }

    return this->GetNumberOfWeightClasses();
}