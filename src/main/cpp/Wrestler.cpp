#include "../headers/Wrestler.h"

std::default_random_engine Wrestler::engine = std::default_random_engine(time(NULL));

Wrestler::Wrestler()
{
    std::uniform_int_distribution<> uid(13, 17);
    
    // Throw away value
    uid(engine);
    this->Age(uid(engine));

    // Just for now
    this->Weight(120);

    std::normal_distribution<> nd{100, 15};
    this->Ability(nd(engine));
}

std::string Wrestler::toString() const
{
    std::string retString;

    retString += "PLACEHOLDER NAME - ";
    retString += "Age: ";
    retString.append(std::to_string(this->Age()));

    retString += ", Weight: ";
    retString.append(std::to_string(this->Weight()));

    retString += ", Ability: ";
    retString.append(std::to_string(this->Ability()));

    return retString;
}