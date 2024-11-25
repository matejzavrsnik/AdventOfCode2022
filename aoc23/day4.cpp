#include <gtest/gtest.h>

#include "day4.h"

using namespace aoc23;

TEST(aoc23, d4_p1)
{
   auto input = read_file_lines("./res/aoc23/day4.txt");
   ASSERT_NE(28567, d4::p1(input)); // too low
   ASSERT_NE(57317, d4::p1(input)); // too high
   ASSERT_EQ(28750, d4::p1(input));
}

TEST(aoc23, d4_p2)
{
   auto input = read_file_lines("./res/aoc23/day4.txt");
   ASSERT_NE(1230, d4::p1(input));
   ASSERT_EQ(10212704, d4::p2(input));
}