#include <gtest/gtest.h>

#include "day12.h"

using namespace aoc24;

TEST(aoc24, d12_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day12.input.txt");
   auto result = d12::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d12_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day12.input.txt");
   auto result = d12::p2(input);
   ASSERT_EQ(1, result);
}