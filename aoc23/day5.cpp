#include <gtest/gtest.h>

#include "day5.h"

using namespace aoc23;

TEST(aoc23, d5_p1)
{
   auto input = read_file_lines("./res/aoc23/day5.txt");
   ASSERT_EQ(1, d5::p1(input));
}

TEST(aoc23, d5_p2)
{
   auto input = read_file_lines("./res/aoc23/day5.txt");
   ASSERT_EQ(1, d5::p2(input));
}