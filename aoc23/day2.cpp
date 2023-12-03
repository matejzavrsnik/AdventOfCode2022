#include <gtest/gtest.h>

#include "day2.h"

using namespace aoc23;

TEST(aoc23, d2_p1)
{
   auto input = read_file_lines("./res/aoc23/day2.txt");
   ASSERT_NE(6230, d2::p1(input)); // too high
   ASSERT_NE(2141, d2::p1(input)); // too low
   ASSERT_NE(2909, d2::p1(input)); // too high
   ASSERT_EQ(2505, d2::p1(input));
}

TEST(aoc23, d2_p2)
{
   auto input = read_file_lines("./res/aoc23/day2.txt");
   ASSERT_EQ(70265, d2::p2(input));
}