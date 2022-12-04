#include "../headers/Wrestler.h"

std::default_random_engine Wrestler::engine = std::default_random_engine(time(NULL));

Wrestler::Wrestler()
{
    std::uniform_int_distribution<> uid(13, 17);
    
    // Throw away value
    uid(engine);
    this->Age(uid(engine));

    this->Weight(this->GenerateWeight());

    std::normal_distribution<> nd{100, 15};
    this->Ability(nd(engine));

    this->ID(0);
}

Wrestler::Wrestler(int id)
{
    std::uniform_int_distribution<> uid(13, 17);
    
    // Throw away value
    uid(engine);
    this->Age(uid(engine));

    this->Weight(this->GenerateWeight());

    std::normal_distribution<> nd{100, 15};
    this->Ability(nd(engine));

    this->ID(id);
}

int Wrestler::GenerateWeight() const
{
    int avWeight = -1;

    switch(this->Age())
    {
        case 13:
            avWeight = 101;
            break;
        case 14:
            avWeight = 110;
            break;
        case 15:
            avWeight = 121;
            break;
        case 16:
            avWeight = 132;
            break;
        case 17:
            avWeight = 145;
            break;
    }

    std::normal_distribution<> nd(avWeight, 15);
    return nd(engine);
}

std::string Wrestler::toString() const
{
    std::string retString;

    retString += "#";
    retString.append(std::to_string(this->ID()));
    retString += "Age: ";
    retString.append(std::to_string(this->Age()));

    retString += ", Weight: ";
    retString.append(std::to_string(this->Weight()));

    retString += ", Ability: ";
    retString.append(std::to_string(this->Ability()));

    return retString;
}