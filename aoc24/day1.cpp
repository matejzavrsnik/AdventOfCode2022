#include <gtest/gtest.h>

#include "day1.h"

using namespace aoc24;

TEST(aoc24, d1_p1)
{
   auto input = read_file_lines("./res/aoc24/day1.input.txt");
   ASSERT_EQ(1889772, d1::p1(input));
}

TEST(aoc24, d1_p2)
{
   auto input = read_file_lines("./res/aoc24/day1.input.txt");
   ASSERT_EQ(23228917, d1::p2(input));
}