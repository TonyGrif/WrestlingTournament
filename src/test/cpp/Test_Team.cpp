#include <gtest/gtest.h>

#include "../../main/headers/Team.h"

TEST(TestTeam, TestDefaultConstructor)
{
    Team defTeam;

    ASSERT_EQ(defTeam.TeamID(), 100);
    ASSERT_NE(defTeam.NumberOfWrestlers(), 0);

    Team secTeam;
    ASSERT_EQ(secTeam.TeamID(), 200);
    ASSERT_NE(secTeam.NumberOfWrestlers(), 0);

    FAIL();
}

TEST(TestTeam, TestInitVector)
{
    Team defTeam;

    //ASSERT_EQ(defTeam.GetNumberOfWeightClasses(), 14);
    FAIL() << "Need more info on if there is a range or one number";

}

TEST(TestTeam, TestAddWrestler)
{
    Team defTeam;
    Wrestler* addWrestler = new Wrestler;

    int startingNum = defTeam.NumberOfWrestlers();
    defTeam.AddWrestler(*addWrestler);
    ASSERT_EQ(startingNum+1, defTeam.NumberOfWrestlers());
}

TEST(TestTeam, TestRecords)
{
    Team defTeam;
    Wrestler *temp;

    ASSERT_EQ(defTeam.GetWins(), 0);
    ASSERT_EQ(defTeam.GetLosses(), 0);

    temp = new Wrestler(104);
    defTeam.IncrementLosses(temp->ID());

    ASSERT_EQ(defTeam.GetWins(), 0);
    ASSERT_EQ(defTeam.GetLosses(), 1);

    ASSERT_EQ(defTeam.GetLossIDs().size(), 1);
    ASSERT_EQ(defTeam.GetLossIDs().front(), temp->ID());
    ASSERT_EQ(defTeam.GetLossIDs().back(), temp->ID());

    temp = new Wrestler(235);
    defTeam.IncrementWins(temp->ID());
    temp = new Wrestler(806);
    defTeam.IncrementWins(temp->ID());

    ASSERT_EQ(defTeam.GetWins(), 2);
    ASSERT_EQ(defTeam.GetLosses(), 1);

    ASSERT_EQ(defTeam.GetWinIDs().size(), 2);
    ASSERT_EQ(defTeam.GetWinIDs().front(), 235);
    ASSERT_EQ(defTeam.GetWinIDs().back(), temp->ID());
}