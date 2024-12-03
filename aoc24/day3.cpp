#include <gtest/gtest.h>

#include "day3.h"

using namespace aoc24;

TEST(aoc24, d3_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day3.input.txt");
   auto result = d3::p1(input);
   ASSERT_EQ(171183089, result);
}

TEST(aoc24, d3_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day3.input.txt");
   auto result = d3::p2(input);
   ASSERT_EQ(63866497, result);
}