#include "../headers/Tournament.h"

Tournament::Tournament()
{
    for(int x = 0; x < 8; x++)
    {
        this->Teams.push_back(*new Team);
    }
}

float Tournament::ConductBout(Wrestler one, Wrestler two)
{
    return -1;
}