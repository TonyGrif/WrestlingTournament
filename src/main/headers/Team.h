#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <queue>

#include <list>

#include "Wrestler.h"

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

        int GetWins() const {
            return this->wins.count;
        }

        int GetLosses() const {
            return this->losses.count;
        }

        void IncrementWins(Wrestler losser) {
            this->wins.count++;
            this->wins.results.push_back(losser);
        }

        void IncrementLosses(Wrestler winner) {
            this->losses.count++;
            this->losses.results.push_back(winner);
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
            std::list<Wrestler> results;
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