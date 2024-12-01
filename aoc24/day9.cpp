#include <gtest/gtest.h>

#include "day9.h"

using namespace aoc24;

TEST(aoc24, d9_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day9.input.txt");
   auto result = d9::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d9_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day9.input.txt");
   auto result = d9::p2(input);
   ASSERT_EQ(1, result);
}