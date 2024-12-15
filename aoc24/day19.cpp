#include <gtest/gtest.h>

#include "day19.h"

using namespace aoc24;

TEST(aoc24, d19_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day19.input.txt");
   auto result = d19::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d19_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day19.input.txt");
   auto result = d19::p2(input);
   ASSERT_EQ(1, result);
}