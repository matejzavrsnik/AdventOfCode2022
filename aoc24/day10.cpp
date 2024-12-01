#include <gtest/gtest.h>

#include "day10.h"

using namespace aoc24;

TEST(aoc24, d10_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day10.input.txt");
   auto result = d10::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d10_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day10.input.txt");
   auto result = d10::p2(input);
   ASSERT_EQ(1, result);
}