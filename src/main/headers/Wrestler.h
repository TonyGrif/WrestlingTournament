#ifndef WRESTLER_H
#define WRESTLER_H

#include <random>
#include <string>

/**
 * @brief Wrestler class responsible for all the information that makes up a Wrestler.
 */
class Wrestler
{
    public:
        /**
         * @brief Construct a new Wrestler object.
         * 
         * Age = 13-17; Ability Score = 100 +- 15.
         */
        Wrestler();

        /**
         * @brief Set the age of this Wrestler.
         * 
         * Set the age of this Wrestler and ensure if falls within the desired range (13 to 17).
         * 
         * @param a Integer.
         */
        void Age(int a) {
            if(a < 13) { this->age  = 13; }
            else if(a > 17) { this->age = 17; }
            else { this->age = a; }
        }

        /**
         * @brief Return the age of this Wrestler.
         * 
         * @return Integer.
         */
        int Age() const {
            return this->age;
        }

        /**
         * @brief Set the weight of this Wrestler.
         * 
         * Set weight while ensuring the number is non-negative.
         * If the weight is negative, set to 100 (throw away number).
         * 
         * @param w Integer.
         */
        void Weight(int w) {
            w <= 0 ? this->weight = 100 : this->weight = w;
        }

        /**
         * @brief Return the weight of this Wrestler.
         * 
         * @return Integer.
         */
        int Weight() const {
            return this->weight;
        }

        /**
         * @brief Set the ability score of this Wrestler.
         * 
         * Set the ability score of this Wrestler while ensuring the score does not dip below zero.
         * 
         * @param as Integer.
         */
        void Ability(int as) {
            as < 0 ? this->abilityScore = 0 : this->abilityScore = as;
        }

        /**
         * @brief Return the ability score of this Wrestler.
         * 
         * @return Integer.
         */
        int Ability() const {
            return this->abilityScore;
        }

        /**
         * @brief Overload the less than operator.
         * 
         * Wrestlers will be sorted based on their ability score.
         * 
         * @param lhs Another Wrestler.
         * @return true if ability score is less than.
         * @return false if ability score is greater than.
         */
        bool operator<(const Wrestler& lhs) const {
            return this->Ability() < lhs.Ability() ? true : false;
        }

        /**
         * @brief Return a string representation of this Wrestler.
         * 
         * @return String.
         */
        std::string toString() const;

    private:
        /**
         * @brief Wrestler's age.
         * 
         * Stores a integer between 13 and 17.
         */
        int age;

        /**
         * @brief Wrestler's weight.
         * 
         * Determined based on the age of this Wrestler.
         */
        int weight;

        /**
         * @brief Determines a wrestler's skill.
         */
        int abilityScore;

        /**
         * @brief Default engine utilized by the constuctor.
         */
        static std::default_random_engine engine;
};

#endif