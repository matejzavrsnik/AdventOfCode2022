#include <gtest/gtest.h>

#include "dayX.h"

using namespace aoc23;

TEST(aoc23, dX_p1)
{
   auto input = read_file_lines("./res/aoc23/dayX.txt");
   ASSERT_EQ(1, dX::p1(input));
}

TEST(aoc23, dX_p2)
{
   auto input = read_file_lines("./res/aoc23/dayX.txt");
   ASSERT_EQ(1, dX::p2(input));
}