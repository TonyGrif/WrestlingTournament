#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <queue>
#include <cstdlib>

#include <list>

#include "Wrestler.h"

/**
 * @brief Static integer to set each individual team ID number.
 * 
 * Incremented by 100 each time.
 * All team members will use this as a starting point for their own numbers.
 */
static int TEAM_ID_NUMBER = 100;

/**
 * @brief Team class responsible for maintenence of a Wrestler collection and W/L record.
 */
class Team
{
    public:
        /**
         * @brief Storage collection of IDs won or lost to.
         */
        using ID_Collection = std::list<int>;

        /**
         * @brief Storage collection of Wrestlers making up this team.
         */
        using Wrestler_Collection = std::priority_queue<Wrestler>;

        /**
         * @brief Construct a new Team object.
         */
        Team();

        /**
         * @brief Add a new Wrestler to the team.
         * 
         * @param w Wrestler object.
         */
        void AddWrestler(Wrestler& w);

        /**
         * @brief Return the number of Wrestlers on this Team.
         * 
         * @return Integer.
         */
        int NumberOfWrestlers() const {
            return this->numOfWrestlers;
        }

        /**
         * @brief Get the Number Of Weight Classes object.
         * 
         * @return Integer.
         */
        int GetNumberOfWeightClasses() const {
            return this->weightClasses.size();
        }

        /**
         * @brief Get the Westlers within a particular weight class queue.
         * 
         * @param loc of the priority queue desired.
         * @return Wrestler_Collection*.
         */
        Wrestler_Collection* GetWrestlersAt(int loc) {
            Wrestler_Collection* wc = &this->weightClasses[loc].pq;
            return wc;
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
        const ID_Collection GetWinIDs() const {
            return this->wins.results;
        }

        /**
         * @brief Return the loss id list.
         * 
         * @return const list of id numbers.
         */
        const ID_Collection GetLossIDs() const {
            return this->losses.results;
        }

        /**
         * @brief Increment the score counter by the supplied Integer.
         * 
         * @param score Integer to increment by.
         */
        void IncrementScore(int score) {
            score >= 0 ? this->currentScore += score : this->currentScore;
        }

        /**
         * @brief Return the current score of this Team.
         * 
         * @return Integer.
         */
        int CurrentScore() const {
            return this->currentScore;
        }

        void ResetScore() {
            this->currentScore = 0;
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
             * @param w Weight for this Weight Class.
             */
            WeightClass(int w) {
                this->weight = w;
            }

            /**
             * @brief Stores the minimum weight of this weight class.
             */
            int weight;

            /**
             * @brief Priority queue of the Wrestlers making up this class.
             * 
             * Wrestlers are stored based on ability score.
             */
            Wrestler_Collection pq;
        };

        /**
         * @brief Collection of Weight Classes.
         */
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
            ID_Collection results;
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
         * @brief The current score of this Team.
         * 
         * Resets to zero at the end of every match.
         */
        int currentScore;

        /**
         * @brief The number of Wrestlers contained in this Team.
         */
        int numOfWrestlers;

        /**
         * @brief Default random engine for Team class.
         */
        static std::default_random_engine eng;

        /**
         * @brief Find the correct weight class for supplied Wrestler.
         * 
         * @param w Wrestler object.
         * @return Integer, location in the Weight Class collection.
         */
        int FindWeightClass(const Wrestler& w) const;

        /**
         * @brief Initialize the vector based on the weight classes provided.
         * 
         * Not at all efficient, but unable to do another way.
         * BETTER WAY - read from text file, gather information from there.
         */
        void InitializeVector();
};

#endif