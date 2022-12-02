#ifndef TEAM_H
#define TEAM_H

#include <queue>

#include "Wrestler.h"

class Team
{
    public:
        /**
         * @brief Construct a new Team object.
         */
        Team();

    private:
        /**
         * @brief Default random engine for Team class.
         */
        static std::default_random_engine eng;
};

#endif