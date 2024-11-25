#include <gtest/gtest.h>

#include "day9.h"

using namespace aoc23;

TEST(aoc23, d9_p1)
{
   vec<string> input = read_file_lines("./res/aoc23/day9.txt");
   auto result = d9::p1(input);
   ASSERT_EQ(1725987467, result);
}

TEST(aoc23, d9_p2)
{
   vec<string> input = read_file_lines("./res/aoc23/day9.txt");
   auto result = d9::p2(input);
   // 19697 too high - forgot to subtract the diffs instead of adding them
   ASSERT_EQ(971, result);
}