#include <gtest/gtest.h>

#include "../../main/headers/Team.h"

TEST(TestTeam, TestDefaultConstructor)
{
    Team defTeam;

    FAIL();
}

TEST(TestTeam, TestInitVector)
{
    Team defTeam;

    //ASSERT_EQ(defTeam.GetNumberOfWeightClasses(), 14);
    FAIL() << "Need more info on if there is a range or one number";

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