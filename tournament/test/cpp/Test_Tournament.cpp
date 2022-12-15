#include <gtest/gtest.h>

#include "../../main/headers/Tournament.h"

TEST(TestTournament, TestConstructor)
{
    Tournament defTourn;

    ASSERT_NE(defTourn.GetNumberOfTeams(), 0);
    ASSERT_EQ(defTourn.GetNumberOfTeams(), 8);
}

TEST(TestTournament, TestILConstructor)
{
    Tournament ilTourn({*new Team, *new Team, *new Team, *new Team});
    ASSERT_NE(ilTourn.GetNumberOfTeams(), 0);
    ASSERT_EQ(ilTourn.GetNumberOfTeams(), 4);

    Tournament oddTourn({*new Team, *new Team, *new Team});
    ASSERT_NE(oddTourn.GetNumberOfTeams(), 3);
    ASSERT_EQ(oddTourn.GetNumberOfTeams(), 4);
}

TEST(TestTournament, TestListConstructor)
{
    std::list<Team> winners{*new Team, *new Team};
    Tournament liTourn(winners);

    ASSERT_NE(liTourn.GetNumberOfTeams(), 0);
    ASSERT_EQ(liTourn.GetNumberOfTeams(), 2);

    std::list<Team> odd{*new Team, *new Team, *new Team};
    Tournament oddTourn(odd);

    ASSERT_NE(oddTourn.GetNumberOfTeams(), 3);
    ASSERT_EQ(oddTourn.GetNumberOfTeams(), 4);
}

TEST(TestTournament, TestConductTournament)
{
    Tournament defTourn;

    Team* winner = defTourn.ConductTournament();
    ASSERT_FALSE(winner == NULL);
    ASSERT_FALSE(winner->GetWins() == 0);
}