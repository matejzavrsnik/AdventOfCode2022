#include <gtest/gtest.h>

#include "day16.h"

using namespace aoc24;

TEST(aoc24, d16_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day16.input.txt");
   auto result = d16::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d16_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day16.input.txt");
   auto result = d16::p2(input);
   ASSERT_EQ(1, result);
}