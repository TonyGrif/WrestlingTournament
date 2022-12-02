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

    temp = new Wrestler();
    defTeam.IncrementLosses(*temp);
    ASSERT_EQ(defTeam.GetWins(), 0);
    ASSERT_EQ(defTeam.GetLosses(), 1);

    FAIL() << "List not tested";
    //defTeam.IncrementWins();
    //defTeam.IncrementWins();

    ASSERT_EQ(defTeam.GetWins(), 2);
    ASSERT_EQ(defTeam.GetLosses(), 1);
}