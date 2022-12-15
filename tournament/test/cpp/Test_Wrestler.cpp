#include <gtest/gtest.h>

#include "../../main/headers/Wrestler.h"

TEST(TestWrestler, TestDefaultConstructor)
{
    Wrestler defWrestler;

    ASSERT_NE(defWrestler.Age(), 0);
    ASSERT_TRUE(defWrestler.Age() >= 13 || defWrestler.Age() <= 17);
    ASSERT_TRUE(defWrestler.Weight() > 0);
    ASSERT_TRUE(defWrestler.Ability() > -1);
    ASSERT_EQ(defWrestler.ID(), 0);

    Wrestler idWrestler(204);

    ASSERT_NE(idWrestler.Age(), 0);
    ASSERT_TRUE(idWrestler.Age() >= 13 || idWrestler.Age() <= 17);

    ASSERT_TRUE(idWrestler.Weight() > 0);
    ASSERT_TRUE(idWrestler.Ability() > -1);
    ASSERT_EQ(idWrestler.ID(), 204);

    Wrestler wrongIDW(-42);

    ASSERT_NE(wrongIDW.Age(), 0);
    ASSERT_TRUE(wrongIDW.Age() >= 13 || wrongIDW.Age() <= 17);

    ASSERT_TRUE(wrongIDW.Weight() > 0);
    ASSERT_TRUE(wrongIDW.Ability() > -1);

    ASSERT_NE(wrongIDW.ID(), -42);
    ASSERT_EQ(wrongIDW.ID(), 0);
}

TEST(TestWrestler, TestBothConstructor)
{
    Wrestler w(407, 120);

    ASSERT_NE(w.Age(), 0);
    ASSERT_TRUE(w.Age() >= 13 || w.Age() <= 17);

    ASSERT_EQ(w.Weight(), 120);
    ASSERT_TRUE(w.Ability() > -1);
    ASSERT_EQ(w.ID(), 407);

    Wrestler badID(-47, 220);

    ASSERT_NE(badID.Age(), 0);
    ASSERT_TRUE(badID.Age() >= 13 || badID.Age() <= 17);

    ASSERT_EQ(badID.Weight(), 220);
    ASSERT_TRUE(badID.Ability() > -1);

    ASSERT_NE(badID.ID(), -47);
    ASSERT_EQ(badID.ID(), 0);

    Wrestler badWeight(458, -220);

    ASSERT_NE(badWeight.Age(), 0);
    ASSERT_TRUE(badWeight.Age() >= 13 || badWeight.Age() <= 17);

    ASSERT_NE(badWeight.Weight(), -220);
    ASSERT_EQ(badWeight.Weight(), 121);    

    ASSERT_TRUE(badWeight.Ability() > -1);
    ASSERT_EQ(badWeight.ID(), 458);
}

TEST(TestWrestler, TestAge)
{
    Wrestler defWrestler;

    ASSERT_NE(defWrestler.Age(), 0);
    ASSERT_TRUE(defWrestler.Age() >= 13 || defWrestler.Age() <= 17);
}

TEST(TestWrestler, TestWeight)
{
    Wrestler defWrestler;
    int startingAge = defWrestler.Age();
    int startingAbility = defWrestler.Ability(); 
    int startingID = defWrestler.ID();

    ASSERT_TRUE(defWrestler.Weight() > 0);

    defWrestler.Weight(157);
    ASSERT_EQ(defWrestler.Weight(), 157);
    defWrestler.Weight(180);
    ASSERT_EQ(defWrestler.Weight(), 180);

    defWrestler.Weight(-20);
    ASSERT_NE(defWrestler.Weight(), -20);
    ASSERT_EQ(defWrestler.Weight(), 121);

    defWrestler.Weight(0);
    ASSERT_NE(defWrestler.Weight(), 0);
    ASSERT_EQ(defWrestler.Weight(), 121);

    ASSERT_EQ(startingAge, defWrestler.Age());
    ASSERT_EQ(startingAbility, defWrestler.Ability());
    ASSERT_EQ(startingID, defWrestler.ID());
}

TEST(TestWrestler, TestAbility)
{
    Wrestler defWrestler;
    int startingAge = defWrestler.Age();
    int startingWeight = defWrestler.Weight(); 
    int startingID = defWrestler.ID();

    ASSERT_TRUE(defWrestler.Ability()> -1);

    defWrestler.Ability(100);
    ASSERT_EQ(defWrestler.Ability(), 100);
    defWrestler.Ability(150);
    ASSERT_EQ(defWrestler.Ability(), 150);

    defWrestler.Ability(-43);
    ASSERT_NE(defWrestler.Ability(), -43);
    ASSERT_EQ(defWrestler.Ability(), 0);

    ASSERT_EQ(startingAge, defWrestler.Age());
    ASSERT_EQ(startingWeight, defWrestler.Weight());
    ASSERT_EQ(startingID, defWrestler.ID());
}

TEST(TestWrestler, TestID)
{
    Wrestler defWrestler;
    int startingAge = defWrestler.Age();
    int startingWeight = defWrestler.Weight(); 
    int startingAbility = defWrestler.Ability();

    ASSERT_TRUE(defWrestler.ID() == 0);

    defWrestler.ID(103);
    ASSERT_TRUE(defWrestler.ID() == 103);

    defWrestler.ID(-35);
    ASSERT_NE(defWrestler.ID(), -35);
    ASSERT_EQ(defWrestler.ID(), 0);

    ASSERT_EQ(startingAge, defWrestler.Age());
    ASSERT_EQ(startingWeight, defWrestler.Weight());
    ASSERT_EQ(startingAbility, defWrestler.Ability());
}

TEST(TestWrestler, TestLessThan)
{
    Wrestler lhs, rhs;

    lhs.Ability(100);
    rhs.Ability(150);
    ASSERT_TRUE(lhs < rhs);

    lhs.Ability(200);
    ASSERT_FALSE(lhs < rhs);

    lhs.Ability(150);
    ASSERT_FALSE(lhs < rhs);

    rhs.ID(500);
    lhs.ID(0);
    ASSERT_FALSE(lhs < rhs);

    rhs.Weight(300);
    lhs.Weight(121);
    ASSERT_FALSE(lhs < rhs);
}

TEST(TestWrestler, TestEquivalence)
{
    Wrestler w1, w2(30);

    ASSERT_FALSE(w1 == w2);

    Wrestler w3;
    w3.Ability(w1.Ability());
    w3.Weight(w1.Weight());
    
    if(w1.Age() != w3.Age()) {
        ASSERT_FALSE(w1 == w3);
    }
    else {
        ASSERT_TRUE(w1 == w3);
    }
}

TEST(TestWrestler, TestToString)
{
    Wrestler defWrestler;

    std::string checkString = defWrestler.toString();

    ASSERT_TRUE(checkString.find(std::to_string(defWrestler.ID())) != std::string::npos);
    ASSERT_TRUE(checkString.find(std::to_string(defWrestler.Age())) != std::string::npos);
    ASSERT_TRUE(checkString.find(std::to_string(defWrestler.Weight())) != std::string::npos);
    ASSERT_TRUE(checkString.find(std::to_string(defWrestler.Ability())) != std::string::npos);

    Wrestler nonDefW(308);

    std::string checkNonDefString = nonDefW.toString();

    ASSERT_TRUE(checkNonDefString.find(std::to_string(nonDefW.ID())) != std::string::npos);
    ASSERT_TRUE(checkNonDefString.find(std::to_string(nonDefW.Age())) != std::string::npos);
    ASSERT_TRUE(checkNonDefString.find(std::to_string(nonDefW.Weight())) != std::string::npos);
    ASSERT_TRUE(checkNonDefString.find(std::to_string(nonDefW.Ability())) != std::string::npos);

    Wrestler doubleParam(204, 100);

    std::string checkDoubleParam = doubleParam.toString();

    ASSERT_TRUE(checkDoubleParam.find(std::to_string(doubleParam.ID())) != std::string::npos);
    ASSERT_TRUE(checkDoubleParam.find(std::to_string(doubleParam.Age())) != std::string::npos);
    ASSERT_TRUE(checkDoubleParam.find(std::to_string(doubleParam.Weight())) != std::string::npos);
    ASSERT_TRUE(checkDoubleParam.find(std::to_string(doubleParam.Ability())) != std::string::npos);
}