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
}

TEST(TestWrestler, TestNonDefaultConstructor)
{
    Wrestler idWrestler(204);

    ASSERT_NE(idWrestler.Age(), 0);
    ASSERT_TRUE(idWrestler.Age() >= 13 || idWrestler.Age() <= 17);

    ASSERT_TRUE(idWrestler.Weight() > 0);

    ASSERT_TRUE(idWrestler.Ability() > -1);

    ASSERT_EQ(idWrestler.ID(), 204);
}

TEST(TestWrestler, TestBothConstructor)
{
    Wrestler w(407, 120);

    ASSERT_NE(w.Age(), 0);
    ASSERT_TRUE(w.Age() >= 13 || w.Age() <= 17);

    ASSERT_TRUE(w.Weight() == 120);

    ASSERT_TRUE(w.Ability() > -1);

    ASSERT_EQ(w.ID(), 407);
}

TEST(TestWrestler, TestAge)
{
    Wrestler defWrestler;

    ASSERT_NE(defWrestler.Age(), 0);

    defWrestler.Age(13);
    ASSERT_EQ(defWrestler.Age(), 13);
    defWrestler.Age(17);
    ASSERT_EQ(defWrestler.Age(), 17);

    defWrestler.Age(4);
    ASSERT_NE(defWrestler.Age(), 4);
    ASSERT_EQ(defWrestler.Age(), 13);

    defWrestler.Age(20);
    ASSERT_NE(defWrestler.Age(), 20);
    ASSERT_EQ(defWrestler.Age(), 17);
}

TEST(TestWrestler, TestAbility)
{
    Wrestler defWrestler;

    ASSERT_NE(defWrestler.Ability(), 0);

    defWrestler.Ability(100);
    ASSERT_EQ(defWrestler.Ability(), 100);
    defWrestler.Ability(150);
    ASSERT_EQ(defWrestler.Ability(), 150);

    defWrestler.Ability(-43);
    ASSERT_NE(defWrestler.Ability(), -43);
    ASSERT_EQ(defWrestler.Ability(), 0);
}

TEST(TestWrestler, TestWeight)
{
    Wrestler defWrestler;

    ASSERT_TRUE(defWrestler.Weight() > 0);

    defWrestler.Weight(157);
    ASSERT_EQ(defWrestler.Weight(), 157);
    defWrestler.Weight(180);
    ASSERT_EQ(defWrestler.Weight(), 180);

    defWrestler.Weight(-20);
    ASSERT_NE(defWrestler.Weight(), -20);
    ASSERT_EQ(defWrestler.Weight(), 121);
}

TEST(TestWrestler, TestID)
{
    Wrestler defWrestler;

    ASSERT_TRUE(defWrestler.ID() == 0);

    defWrestler.ID(103);
    ASSERT_TRUE(defWrestler.ID() == 103);
}

TEST(TestWrestler, TestLessThan)
{
    Wrestler small, big;

    small.Ability(100);
    big.Ability(150);

    ASSERT_TRUE(small < big);

    small.Ability(200);
    ASSERT_FALSE(small < big);
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
}