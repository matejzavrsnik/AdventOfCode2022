#include <gtest/gtest.h>

#include "day14.h"

using namespace aoc24;

TEST(aoc24, d14_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day14.input.txt");
   auto result = d14::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, dX_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day14.input.txt");
   auto result = d14::p2(input);
   ASSERT_EQ(1, result);
}