#include <gtest/gtest.h>

#include "day6.h"

using namespace aoc23;

TEST(aoc23, d6_p1)
{
   auto input = read_file_lines("./res/aoc23/day6.txt");
   auto result = d6::p1(input);
   ASSERT_NE(1302, result); // too low
   ASSERT_EQ(1624896, d6::p1(input));
}

TEST(aoc23, d6_p2)
{
   auto input = read_file_lines("./res/aoc23/day6.txt");
   auto result = d6::p2(input);
   ASSERT_EQ(32583852, result);
}