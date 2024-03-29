#include <gtest/gtest.h>

#include "../../main/headers/Team.h"

TEST(TestTeam, TestDefaultConstructor)
{
    Team defTeam;

    ASSERT_TRUE(defTeam.TeamID() % 100 == 0);
    ASSERT_NE(defTeam.NumberOfWrestlers(), 0);
    ASSERT_EQ(defTeam.GetNumberOfWeightClasses(), 15);
    ASSERT_EQ(defTeam.CurrentScore(), 0);
    ASSERT_EQ(defTeam.GetWins(), 0);
    ASSERT_EQ(defTeam.GetLosses(), 0);

    Team secTeam;
    ASSERT_TRUE(secTeam.TeamID() % 100 == 0);
    ASSERT_NE(secTeam.NumberOfWrestlers(), 0);
    ASSERT_EQ(secTeam.GetNumberOfWeightClasses(), 15);
    ASSERT_EQ(secTeam.CurrentScore(), 0);
    ASSERT_EQ(secTeam.GetWins(), 0);
    ASSERT_EQ(secTeam.GetLosses(), 0);

    for(int x = 0; x < defTeam.GetNumberOfWeightClasses(); x++)
    {
        ASSERT_NE(defTeam.GetWrestlersAt(x)->size(), 0);
        ASSERT_NE(secTeam.GetWrestlersAt(x)->size(), 0);

        int startSize = defTeam.GetWrestlersAt(x)->size();
        while(!defTeam.GetWrestlersAt(x)->empty())
        {
            ASSERT_TRUE(defTeam.GetWrestlersAt(x)->top().ID() >= defTeam.TeamID()
                && defTeam.GetWrestlersAt(x)->top().ID() < (defTeam.TeamID()+100));

            if(defTeam.GetWrestlersAt(x)->size() != 1)
            {
                Wrestler testing = defTeam.GetWrestlersAt(x)->top();
                defTeam.GetWrestlersAt(x)->pop();
                ASSERT_FALSE(testing == defTeam.GetWrestlersAt(x)->top());
                ASSERT_TRUE(testing.Ability() >= defTeam.GetWrestlersAt(x)->top().Ability());
            }
            else
            {
                defTeam.GetWrestlersAt(x)->pop();
            }

            ASSERT_EQ(startSize, defTeam.GetWrestlersAt(x)->size()+1);
            startSize--;
        }
    }
}

TEST(TestTeam, TestAddWrestler)
{
    Team defTeam;
    Wrestler* addWrestler = new Wrestler;

    int startingNum = defTeam.NumberOfWrestlers();
    defTeam.AddWrestler(*addWrestler);
    ASSERT_EQ(defTeam.NumberOfWrestlers(), startingNum+1);
    startingNum++;
    delete addWrestler;

    // Location number 7
    int sevenCount = defTeam.GetWrestlersAt(7)->size();
    addWrestler = new Wrestler(0, 145);
    addWrestler->Ability(defTeam.GetWrestlersAt(7)->top().Ability()+1);
    defTeam.AddWrestler(*addWrestler);
    ASSERT_EQ(defTeam.GetWrestlersAt(7)->size(), sevenCount+1);
    ASSERT_EQ(defTeam.NumberOfWrestlers(), startingNum+1);

    for(int x = 0; x < defTeam.GetWrestlersAt(7)->size(); x++)
    {
        if(defTeam.GetWrestlersAt(7)->top().Ability() == addWrestler->Ability()) {
            // End this test as a pass
            return;
        }
        else {
            defTeam.GetWrestlersAt(7)->pop();
        }
    }
    FAIL() << "Wrestler not found post-add function";
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

    temp = new Wrestler(235);
    defTeam.IncrementWins(temp->ID());
    temp = new Wrestler(806);
    defTeam.IncrementWins(temp->ID());

    ASSERT_EQ(defTeam.GetWins(), 2);
    ASSERT_EQ(defTeam.GetLosses(), 1);
}

TEST(TestTeam, TestRecordsIDs)
{
    Team defTeam;
    Wrestler *temp;

    temp = new Wrestler(104);
    defTeam.IncrementLosses(temp->ID());

    ASSERT_EQ(defTeam.GetLossIDs().front(), temp->ID());

    temp = new Wrestler(305);
    defTeam.IncrementWins(temp->ID());

    ASSERT_EQ(defTeam.GetWinIDs().front(), temp->ID());
}

TEST(TestTeam, TestScore)
{
    Team defTeam;

    ASSERT_EQ(defTeam.CurrentScore(), 0);

    defTeam.IncrementScore(7);
    ASSERT_EQ(defTeam.CurrentScore(), 7);

    defTeam.IncrementScore(4);
    ASSERT_EQ(defTeam.CurrentScore(), 11);

    defTeam.IncrementScore(-6);
    ASSERT_EQ(defTeam.CurrentScore(), 11);
}