#include <gtest/gtest.h>

#include "day15.h"

using namespace aoc24;

TEST(aoc24, d15_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day15.input.txt");
   auto result = d15::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, dX_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day15.input.txt");
   auto result = d15::p2(input);
   ASSERT_EQ(1, result);
}