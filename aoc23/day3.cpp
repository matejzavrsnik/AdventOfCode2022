#include <gtest/gtest.h>

#include "day3.h"

using namespace aoc23;

TEST(aoc23, d3_p1)
{
   auto input = read_file_lines("./res/aoc23/day3.txt");
   ASSERT_NE(594541, d3::p1(input)); // too high
   ASSERT_EQ(535351, d3::p1(input));
}

TEST(aoc23, d3_p2)
{
   auto input = read_file_lines("./res/aoc23/day3.txt");
   ASSERT_EQ(87287096, d3::p2(input));
}