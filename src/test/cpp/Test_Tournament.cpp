#include <gtest/gtest.h>

#include "../../main/headers/Tournament.h"

TEST(TestTournament, TestConstructor)
{
    Tournament defTourn;

    ASSERT_NE(defTourn.GetNumberOfTeams(), 0);
    ASSERT_EQ(defTourn.GetNumberOfTeams(), 8);
}

TEST(TestTournament, TestMatch)
{
    Tournament defTourn;

    defTourn.ConductMatch(*defTourn.GetTeamAt(0), *defTourn.GetTeamAt(1));
}