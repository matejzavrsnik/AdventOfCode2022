#include <gtest/gtest.h>

#include "day6.h"

using namespace aoc24;

TEST(aoc24, d6_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day6.input.txt");
   auto result = d6::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d6_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day6.input.txt");
   auto result = d6::p2(input);
   ASSERT_EQ(1, result);
}