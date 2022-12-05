#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Team.h"

class Tournament
{
    public:
        /**
         * @brief Construct a new Tournament object.
         * 
         * Create 8 teams and store them.
         */
        Tournament();

        /**
         * @brief Conduct a match between 2 teams.
         * 
         * Pair the front of each pq (same weight class) and have the fronts conduct a bout.
         * 
         * @param one First Team.
         * @param two Second Team.
         */
        void ConductMatch(Team one, Team two);

        /**
         * @brief Get the Number Of Team objects in collection.
         * 
         * @return Integer.
         */
        int GetNumberOfTeams() const {
            return this->Teams.size();
        }

        /**
         * @brief Return a team pointer based on location in the collection.
         * 
         * @param loc Integer location.
         * @return Team*.
         */
        Team* GetTeamAt(int loc) {
            Team *tPtr = &this->Teams[loc];
            return tPtr;
        }

    private:
        /**
         * @brief Collection of Teams.
         */
        std::vector<Team> Teams;

        /**
         * @brief Conduct a bout between 2 Wrestlers.
         * 
         * Comnpare the two abilities of both wrestlers and 
         * 
         * @param one First Wrestler.
         * @param two Second Wrestler.
         * 
         * @return Float score. 
         */
        float ConductBout(Wrestler one, Wrestler two);
};

#endif