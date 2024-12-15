#include <gtest/gtest.h>

#include "day17.h"

using namespace aoc24;

TEST(aoc24, d17_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day17.input.txt");
   auto result = d17::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d17_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day17.input.txt");
   auto result = d17::p2(input);
   ASSERT_EQ(1, result);
}