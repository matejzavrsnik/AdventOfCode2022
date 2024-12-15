#include <gtest/gtest.h>

#include "day18.h"

using namespace aoc24;

TEST(aoc24, d18_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day18.input.txt");
   auto result = d18::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d18_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day18.input.txt");
   auto result = d18::p2(input);
   ASSERT_EQ(1, result);
}