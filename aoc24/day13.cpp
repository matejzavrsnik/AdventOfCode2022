#include <gtest/gtest.h>

#include "day13.h"

using namespace aoc24;

TEST(aoc24, d13_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day13.input.txt");
   auto result = d13::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d13_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day13.input.txt");
   auto result = d13::p2(input);
   ASSERT_EQ(1, result);
}