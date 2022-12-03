#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <queue>

#include <list>

#include "Wrestler.h"

/**
 * @brief Static integer to set each individual team ID number
 * 
 * Incremented by 100 each time.
 * All team members will use this as a starting point for their own numbers.
 */
static int TEAM_ID_NUMBER = 100;

class Team
{
    public:
        /**
         * @brief Construct a new Team object.
         */
        Team();

        /**
         * @brief Add a new Wrestler to the team.
         * 
         * @param w Wrestler object.
         */
        void AddWrestler(Wrestler w);

        /**
         * @brief Get the Number Of Weight Classes object.
         * 
         * @return Integer.
         */
        int GetNumberOfWeightClasses() const {
            return this->weightClasses.size();
        }

        /**
         * @brief Return the number of wins this Team has.
         * 
         * @return Integer.
         */
        int GetWins() const {
            return this->wins.count;
        }

        /**
         * @brief Return the number of losses this Team has.
         * 
         * @return Integer.
         */
        int GetLosses() const {
            return this->losses.count;
        }

        /**
         * @brief Increment the wins counter and add the ID to a list.
         * 
         * @param losser the ID of the losser of the match.
         */
        void IncrementWins(int losser) {
            this->wins.count++;
            this->wins.results.push_back(losser);
        }

        /**
         * @brief Increment the losses counter and add the ID to a list.
         * 
         * @param winner the ID of the winner of the match.
         */
        void IncrementLosses(int winner) {
            this->losses.count++;
            this->losses.results.push_back(winner);
        }

        /**
         * @brief Return the wins id list.
         * 
         * @return const list of id numbers.
         */
        const std::list<int> GetWinIDs() const {
            return this->wins.results;
        }

        /**
         * @brief Return the loss id list.
         * 
         * @return const list of id numbers.
         */
        const std::list<int> GetLossIDs() const {
            return this->losses.results;
        }

        /**
         * @brief Return this Team's identification number.
         * 
         * @return Integer.
         */
        int TeamID() const {
            return this->teamID;
        }

    private:
        /**
         * @brief Stores the information relating to one weight class.
         */
        struct WeightClass
        {
            /**
             * @brief Construct a new Weight Class object.
             * 
             * @param min Minimum weight.
             * @param max Maximum weight.
             */
            WeightClass(int min, int max) {
                this->minWeight = min;
                this->maxWeight = max;
            }

            /**
             * @brief Stores the minimum weight of this weight class.
             */
            int minWeight;

            /**
             * @brief Stores the maximum weight of this weight class.
             */
            int maxWeight;

            /**
             * @brief Priority queue of the Wrestlers making up this class.
             * 
             * Wrestlers are stored based on ability score.
             */
            std::priority_queue<Wrestler> pq;
        };

        std::vector<WeightClass> weightClasses;

        /**
         * @brief Collection for the wins or loses of the team and a list of who they lost to.
         */
        struct Records
        {
            Records() {
                this->count = 0;
            }

            /**
             * @brief Current count of record.
             */
            int count;

            /**
             * @brief List of who was beaten/lost to.
             */
            std::list<int> results;
        };

        /**
         * @brief Stores the number of wins this team has had.
         */
        Records wins;

        /**
         * @brief Stores the number of loses this team has had.
         */
        Records losses;

        /**
         * @brief Team's identification number.
         * 
         * Must be determined at creation.
         */
        const int teamID;

        /**
         * @brief Default random engine for Team class.
         */
        static std::default_random_engine eng;

        /**
         * @brief Initialize the vector based on the weight classes provided.
         * 
         * Not at all efficient, but unable to do another way.
         */
        void InitializeVector();
};

#endif